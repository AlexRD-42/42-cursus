/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:44:59 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/13 12:23:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	int	i;

	if (c == 0)
		return (0);
	i = 0;
	while (charset[i] != 0)
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_cwords(char *str, char *sep)
{
	int	i;
	int	flag;
	int	count;

	i = 0;
	count = 0;
	flag = 1;
	while (str[i] != 0)
	{
		if (!ft_is_sep(str[i], sep) && flag == 1)
		{
			count++;
			flag = 0;
		}
		if (ft_is_sep(str[i], sep))
		{
			flag = 1;
		}
		i++;
	}
	return (count);
}

char	*ft_create(char *str, int word_size)
{
	char	*new_str;
	int		i;

	new_str = (char *) malloc(word_size + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < word_size)
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	dest = (char **) malloc((ft_cwords(str, charset) + 1) * sizeof(char *));
	while (str[i] != 0)
	{
		if (ft_is_sep(str[i], charset) || i == 0)
		{
			j = ++i;
			while (str[i] != 0 && !ft_is_sep(str[i], charset))
				i++;
			if (i > j)
				dest[k++] = ft_create(&str[j - (j == 1)], i - j + (j == 1));
		}
		else
			i++;
	}
	dest[k] = 0;
	return (dest);
}

#include <stdio.h>
int main()
{
	char *str = "ab cd,,efgh,,k,+,x,";
	char **str2;
	char *sep = ",+";
	printf("====\n");
	str2 = ft_split(str, sep);
	int i = 0;
	while (str2[i] != 0)
	{
		printf("%s\n", str2[i]);
		i++;
	}
}