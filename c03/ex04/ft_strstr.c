/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:31:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:22:19 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// iterations should be str1Size - str2Size
// second loop should be size of str2Size
// return is a pointer to the beginning of substring found

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	str_length;
	int	substr_length;
	int	matches;

	i = 0;
	str_length = ft_strlen(str);
	substr_length = ft_strlen(to_find);
	while (i <= (str_length - substr_length))
	{
		j = 0;
		matches = 0;
		while (j < substr_length)
		{
			if (str[i + j] == to_find[j])
				matches++;
			j++;
		}
		if (matches == substr_length)
			return (str + i);
		i++;
	}
	return ('0');
}

// int main(void)
// {
//     char str[] = "ddkahCt";
//     char substr[] = "Cat";
//     printf("%s", ft_strstr(str, substr));
// }