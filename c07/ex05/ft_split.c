/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:44:59 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 12:44:59 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

int	ft_is_sep(char *str, char *sep, int i)
{
	int	j;

	j = 0;
	while (sep[j] != 0 && str[i] != 0)
	{
		if (sep[j] != str[i])
			return (0);
		i++;
		j++;
	}
	return (1);
}

int ft_count_words(char *str, char *sep)
{
    int i;
    int flag;
    int count;

    i = 0;
    count = 0;
    flag = 1;

    while (str[i] != 0)
    {
        if (!ft_is_sep(str, sep, i) && flag == 1)
        {
            count++;
            flag = 0;
        }
        if (ft_is_sep(str, sep, i))
        {
            flag = 1;
        }
        i++;
    }
    return (count);
}

char *ft_create(char *str, int word_size, char *charset)
{
	int	sep_size;
    int i;
	int	j;
    char *new_str;

	j = 0;
	sep_size = 0;
	while (charset[sep_size] != 0)
		sep_size++;
    new_str = (char *) malloc(2 * sep_size + word_size + 1);
    i = -1;
	while (++i < sep_size)
		new_str[j++] = charset[i];
	i = -1;
	while (++i < word_size)
		new_str[j++] = str[i];
	i = -1;
	while (++i < sep_size)
		new_str[j++] = charset[i];
    new_str[j] = 0;
    return (new_str);
}

char **ft_split(char *str, char *charset)
{
    int i;
    int j;
    int k;
    char **str2;

	i = 0;
    k = 0;
    str2 = (char **) malloc((ft_count_words(str, charset) + 1) * sizeof(char*));
    while (str[i] != 0)
    {
        if (ft_is_sep(str, charset, i) || (i == 0 && !ft_is_sep(str, charset, i)))
        {
            j = i++;
            while (!ft_is_sep(str, charset, i))
                i++;
            if (i != j)
				str2[k++] = ft_create(&str[j], i - j, charset);
			i--;
        }
        i++;
    }
	str2[k] = 0;
    return (str2);
}

#include <stdio.h>
int main()
{
	char *str = "abcd,,efgh,,ija,,k,,";
	char **str2;
	char *sep = ",,";

	str2 = ft_split(str, sep);

	printf("%s\n", str2[0]);
	printf("%s\n", str2[1]);
	printf("%s\n", str2[2]);
	printf("%s", str2[3]);
}