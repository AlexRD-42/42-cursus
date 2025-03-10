/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:09:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 00:09:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_string.h"
#include "ft_bool.h"
#include <stdlib.h>
#include <unistd.h>

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