#ifndef HELPERS_H
#define HELPERS_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

// Function declarations
int     is_digit(char c);
int     is_space(char c);
int     is_alpha(char c);
int     ft_strlen(char *str);
char    *ft_strncpy(char *src, unsigned int n);
char    *ft_strncat(char *dest, char *src, int n);
char    *zero_pad(char *str, int n);
int     ft_atoi(char *str);
void    ft_printstr(char *str, int print_flag);
char    *read_file(int *totalsize, char *filename);
char    *parse_digit(char *str, int *i, int *flag);
char    *parse_text(char *str, int *i, int *flag);
void    parse_line(char *str, char **num_str, char **text_str, int *index);
int     index_lookup(char *num_str);
char    **parse_input(char *str, int totalsize);
void    num2str(int d[4], char **dict);
void    ft_free(char ***dict, char **input, char **str);
void	ft_start(char *num, char **dict);
void    handle_input(char *input, char *str);
char    *get_dictionary(char *filename, int *totalsize);

// Function Implementations
int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int	is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

char	*ft_strncpy(char *src, unsigned int n)
{
	unsigned int	i;
	char			*str;

	str = (char *) malloc(n + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 0 && i < n)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_strncat(char *dest, char *src, int n)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	str = (char *) malloc (n + 1);
	while (dest[i] != 0)
	{
		str[i] = dest[i];
		i++;
	}
	j = 0;
	while (src[j] != 0)
	{
		str[i + j] = src[j];
		j++;
	}
	str[i + j] = 0;
	return (str);
}

char	*zero_pad(char *str, int n)
{
	int		str_length;

	str_length = ft_strlen(str);
	if (n == 0)
		return (ft_strncpy(str, str_length));
	else if (n == 1)
		return (ft_strncat("00", str, str_length + 2));
	else if (n == 2)
		return (ft_strncat("0", str, str_length + 1));
	else
		return (NULL);
}

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

void	ft_printstr(char *str, int print_flag)
{
	char	c;

	if (*str == 0)
	{
		write(1, "Dict Error\n", 12);
		return ;
	}
	while (*str != 0)
	{
		c = *str;
		write(1, &c, 1);
		str++;
	}
	if (print_flag == 1)
		write(1, "-", 1);
}

char	*read_file(int *totalsize, char *filename)
{
	char	*buffer;
	char	*str;
	int		fd;
    int		bytesRead;

	*totalsize = 0;
	buffer = (char *) malloc(128);
	fd = open(filename, O_RDONLY);
	if (fd != -1 && buffer != NULL)
		while ((bytesRead = read(fd, buffer, 128)) > 0)
			*totalsize += bytesRead;
	close(fd);
	free(buffer);
	str = (char *) malloc(*totalsize + 1);
	fd = open(filename, O_RDONLY);
	if (fd != -1 && str != NULL)
	{
		bytesRead = read(fd, str, *totalsize);
		str[*totalsize] = 0;
	}
	close(fd);
	return (str);
}

char	*parse_digit(char *str, int *i, int *flag)
{
	int	j;
	int	start;

	start = *i;
	j = 0;
	while (is_digit(str[j + start]) == 1)
		j++;
	*i += j - 1;
	*flag = 1;
	return (ft_strncpy(&str[start], j));
}

char	*parse_text(char *str, int *i, int *flag)
{
	int	j;
	int	start;

	start = *i;
	j = 0;
	while (is_alpha(str[j + start]) == 1)
		j++;
	*i += j - 1;
	*flag = 1;
	return (ft_strncpy(&str[start], j));
}

void	parse_line(char *str, char **num_str, char **text_str, int *index)
{
	int		digit;
	int		text;
	int		i;

	digit = 0;
	text = 0;
	i = *index;
	while (str[i] != 0 && str[i] != 10 && str[i] != ':')
	{
		if (is_digit(str[i]) && digit == 0)
			*num_str = parse_digit(str, &i, &digit);
		i++;
	}
	while (str[i] != 0 && str[i] != 10)
	{
		if (is_alpha(str[i]) && text == 0)
			*text_str = parse_text(str, &i, &text);
		i++;
	}
	if (str[i] == 10)
		i++;
	*index = i;
}

int	index_lookup(char *num_str)
{
	int		n;
	int		index;

	n = ft_strlen(num_str);
	if (n <= 3)
		index = ft_atoi(num_str);
	else
		return (28 + n / 3);
	if (index == 100)
		return(28);
	if (index >= 20)
		index = (index - 20) / 10 + 20;
	return (index);
}

char	**parse_input(char *str, int totalsize)
{
	char	**dict;
	char	*num_str;
	char	*text_str;
	int		i;
	int		index;

	dict = (char **) malloc(42 * sizeof(char *));
	i = 0;
	while (i < 42)
		dict[i++] = NULL;
	i = 0;
	while (i < totalsize)
	{
		parse_line(str, &num_str, &text_str, &i);
		index = index_lookup(num_str);
		if (index >= 0 || index <= 41)
			dict[index] = text_str;
	}
	return(dict);
}

void num2str(int d[4], char **dict)
{
	if (d[0] != 0)
	{
		ft_printstr(dict[d[0]], 1);
		ft_printstr(dict[28], 1);
	}
	if (d[1] >= 2)
	{
		ft_printstr(dict[d[1] + 18], 1);
		if (d[2] != 0)
			ft_printstr(dict[d[2]], 1);
	}
	else if (d[1] != 0 || d[2] != 0)
		ft_printstr(dict[d[1] * 10 + d[2]], 1);
	else
		ft_printstr(dict[0], 1);
	if (d[3] > 0)
		ft_printstr(dict[d[3] + 28], 1);
}

void	ft_free(char ***dict, char **input, char **str)
{
	int	i;

	i = 0;
	while (i < 42)
	free((*dict)[i++]);
	free(*dict);
	free(*input);
	free(*str);
}

void	ft_start(char *num, char **dict)
{
	int	d[4];
	int	n;
	int	mag;
	int	i;

	n = ft_strlen(num);
	mag = (n / 3) - 1;
	i = 0;
	while (mag >= 0)
	{
		d[0] = num[i] - '0';
		d[1] = num[i + 1] - '0';
		d[2] = num[i + 2] - '0';
		d[3] = mag;
		i += 3;
		mag--;
		num2str(d, dict);
	}
	write(1, "\n", 1);
}

void handle_input(char *input, char *str)
{
    char    **dict;
    char    *padded_input;
    
    dict = parse_input(str, ft_strlen(str));
    padded_input = zero_pad(input, ft_strlen(input) % 3);
    ft_start(padded_input, dict);
    ft_free(&dict, &padded_input, &str);
}

char *get_dictionary(char *filename, int *totalsize)
{
    char *str = read_file(totalsize, filename);
    if (str == NULL)
    {
        write(1, "Dict Error\n", 11);
        return (NULL);
    }
    return (str);
}
#endif