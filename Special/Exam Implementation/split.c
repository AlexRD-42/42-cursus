#include <stdlib.h>
#include <stdio.h>

int count_words(char *str)
{
    int i;
    int flag;
    int count;

    i = 0;
    count = 0;
    flag = 1;

    while (str[i] != 0)
    {
        if ((str[i] != 32 && str[i] != 10 && str[i] != 9) && flag == 1)
        {
            count++;
            flag = 0;
        }
        if (str[i] == 32 || str[i] == 10 || str[i] == 9)
        {
            flag = 1;
        }
        i++;
    }
    return (count);
}

char *ft_create(char *str, int start, int end)
{
    int size;
    int i;
    char *new_str;

    size = end - start + 1;
    new_str = (char *) malloc(size);
    i = 0;
    while (i < (size - 1))
    {
        new_str[i] = str[i + start];
        i++;
    }
    new_str[i] = 0;
    return (new_str);
}

char **ft_split(char *str)
{
    int size;
    int i;
    int j;
    int k;
    char **str2;

    size = count_words(str);
    str2 = (char **) malloc((size + 1) * sizeof(char*));
    k = 0;
    i = 0;
    while (str[i] != 0)
    {
        if ((str[i] != 32 && str[i] != 10 && str[i] != 9 && str[i] != 0))
        {
            j = i;
            while ((str[j] != 32 && str[j] != 10 && str[j] != 9 && str[j] != 0))
                j++;
            str2[k] = ft_create(str, i, j);
            i = j;
            k++;
        }
        i++;
    }
	str2[k] = NULL;
    return (str2);
}


int main()
{
	char *str = "This is\na\tstring and a longer string ok maybe this hsouldnt work then if the string is longer is what youre saying";
	char **str2;
	char *sep = "\t\n ";

	str2 = ft_split(str);

	printf("%s\n", str2[0]);
	printf("%s\n", str2[1]);
	printf("%s\n", str2[2]);
	printf("%s", str2[3]);
}