#include <stdlib.h>
#include <string.h>

// Function to check if character is a digit
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

// Function to check if character is a space
int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

// Function to convert string to number (like atoi)
int ft_atoi(char *str)
{
    int i;
    int sign;
    unsigned int num;

    i = 0;
    sign = 1;
    num = 0;
    while (is_space(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (is_digit(str[i]))
    {
        num = (num * 10) + (str[i] - '0');
        i++;
    }
    return (sign * num);
}

// Function to trim leading spaces
char *trim_leading(char *str)
{
    if (!str || *str == '\0')
        return str;
    while (is_space(*str))
        str++;
    return str;
}

// Function to trim trailing spaces
char *trim_trailing(char *str)
{
    char *end;
    
    if (!str || *str == '\0')
        return str;
    end = str + strlen(str) - 1;
    while (end > str && is_space(*end))
        end--;
    *(end + 1) = '\0';
    return str;
}

// Function to trim spaces before and after a string
char *trim_spaces(char *str)
{
    return trim_trailing(trim_leading(str));
}

// Function to initialize dictionary arrays
void init_dict_arrays(char **uni_dict, char **dec_dict, char **mag_dict)
{
    int i;
    
    for (i = 0; i < 20; i++)
        uni_dict[i] = NULL;
    for (i = 0; i < 8; i++)
        dec_dict[i] = NULL;
    for (i = 0; i < 5; i++)
        mag_dict[i] = NULL;
}

// Function to skip to next line
int skip_to_next_line(char *str, int i)
{
    while (str[i] && str[i] != '\n')
        i++;
    if (str[i])
        i++;
    return i;
}

// Function to extract number from a line
int extract_number(char *dict_str, int start, int colon)
{
    char *num_str;
    char *trimmed_num;
    int number;
    
    num_str = malloc(colon - start + 1);
    if (!num_str)
        return -1;
    strncpy(num_str, dict_str + start, colon - start);
    num_str[colon - start] = '\0';
    trimmed_num = trim_spaces(num_str);
    number = ft_atoi(trimmed_num);
    free(num_str);
    return number;
}

// Function to extract word from a line
char *extract_word(char *dict_str, int colon, int end)
{
    char *word;
    char *trimmed_word;
    char *final_word;
    
    word = malloc(end - colon);
    if (!word)
        return NULL;
    strncpy(word, dict_str + colon + 1, end - colon - 1);
    word[end - colon - 1] = '\0';
    trimmed_word = trim_spaces(word);
    final_word = strdup(trimmed_word);
    free(word);
    return final_word;
}

// Function to store word in appropriate array
int store_word(int number, char *word, char **uni_dict, char **dec_dict, char **mag_dict)
{
    if (number >= 0 && number <= 19)
    {
        if (uni_dict[number])
            free(uni_dict[number]);
        uni_dict[number] = word;
        return 1;
    }
    else if (number >= 20 && number <= 90 && number % 10 == 0)
    {
        int idx = (number / 10) - 2;
        if (dec_dict[idx])
            free(dec_dict[idx]);
        dec_dict[idx] = word;
        return 1;
    }
    else if (number == 100 || number == 1000 || number == 1000000 || 
             number == 1000000000 || number == 1000000000000)
    {
        int idx = 0;
        if (number == 1000) idx = 1;
        else if (number == 1000000) idx = 2;
        else if (number == 1000000000) idx = 3;
        else if (number == 1000000000000) idx = 4;
        if (mag_dict[idx])
            free(mag_dict[idx]);
        mag_dict[idx] = word;
        return 1;
    }
    free(word);
    return 0;
}

// Function to process a dictionary line
int process_dict_line(char *dict_str, int i, char **uni_dict, char **dec_dict, char **mag_dict)
{
    int start, colon, end;
    int number;
    char *word;
    
    start = i;
    while (dict_str[i] && dict_str[i] != ':' && dict_str[i] != '\n')
        i++;
    if (dict_str[i] != ':')
        return skip_to_next_line(dict_str, i);
    colon = i++;
    while (dict_str[i] && dict_str[i] != '\n')
        i++;
    end = i;
    number = extract_number(dict_str, start, colon);
    if (number < 0)
        return skip_to_next_line(dict_str, i);
    word = extract_word(dict_str, colon, end);
    if (!word)
        return skip_to_next_line(dict_str, i);
    store_word(number, word, uni_dict, dec_dict, mag_dict);
    return i;
}

// Function to check if all required entries are present
int check_entries(char **uni_dict, char **dec_dict, char **mag_dict)
{
    int i;
    
    for (i = 0; i < 20; i++)
        if (!uni_dict[i])
            return 0;
    for (i = 0; i < 8; i++)
        if (!dec_dict[i])
            return 0;
    if (!mag_dict[0] || !mag_dict[1])
        return 0;
    return 1;
}

// Main parse dictionary function
int parse_dictionary(char *dict_str, char **uni_dict, char **dec_dict, char **mag_dict)
{
    int i;
    
    init_dict_arrays(uni_dict, dec_dict, mag_dict);
    i = 0;
    while (dict_str[i])
    {
        while (dict_str[i] && is_space(dict_str[i]))
            i++;
        if (dict_str[i] == '\n')
        {
            i++;
            continue;
        }
        if (!is_digit(dict_str[i]))
        {
            i = skip_to_next_line(dict_str, i);
            continue;
        }
        i = process_dict_line(dict_str, i, uni_dict, dec_dict, mag_dict);
        if (dict_str[i])
            i++;
    }
    return check_entries(uni_dict, dec_dict, mag_dict);
}

// Function to free allocated memory for dictionary
void free_dictionary(char **uni_dict, char **dec_dict, char **mag_dict)
{
    int i;
    
    if (uni_dict)
        for (i = 0; i < 20; i++)
            if (uni_dict[i])
                free(uni_dict[i]);
    if (dec_dict)
        for (i = 0; i < 8; i++)
            if (dec_dict[i])
                free(dec_dict[i]);
    if (mag_dict)
        for (i = 0; i < 5; i++)
            if (mag_dict[i])
                free(mag_dict[i]);
}