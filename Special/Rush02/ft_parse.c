/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:12:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 00:12:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_parse.h"
#include "ft_bool.h"
#include "ft_string.h"
#include <stdlib.h>

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
		if (index >= 0 && index <= 41)
			dict[index] = text_str;
	}
	return(dict);
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