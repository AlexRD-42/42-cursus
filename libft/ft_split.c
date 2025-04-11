/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 16:35:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 18:48:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_checkstr(char **str_array, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		if (str_array[i] == NULL)
			break ;
		i++;
	}
	if (i == count)
		return (str_array);
	i = 0;
	while (i < count)
	{
		if (str_array[i] != NULL)
			free(str_array[i]);
		i++;
	}
	free(str_array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char		**str_array;
	int64_t		len;
	size_t		count;

	len = 0;
	count = (s[0] != c && s[0] != 0) || (s[0] == c && s[(*s != 0)] != c);
	while (s[len++] != 0)
		count += s[len] == c && s[len + 1] != c && s[len + 1] != 0;
	str_array = malloc((count + 1) * sizeof(char *));
	count = 0;
	if (str_array == NULL)
		return (NULL);
	while (*s != 0)
	{
		len = ft_strchr(s, c) - s;
		len = (len < 0) * ft_strlen(s) + (len > 0) * len;
		if (len > 0)
			str_array[count++] = ft_substr(s, 0, len);
		s += (s[len] != 0) + len;
	}
	str_array[count] = 0;
	return (ft_checkstr(str_array, count));
}
