/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:14:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:34:48 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// name should be atoi dumbass
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

int	ft_pow(int num, int exp)
{
	int	base;

	base = num;
	if (exp == 0)
		return (1);
	else
	{
		while (exp > 1)
		{
			num = num * base;
			exp--;
		}
	}
	return (num);
}

int	ft_atoi(char *str)
{
	int	str_length;
	int	value;
	int	i;

	i = 0;
	str_length = ft_strlen(str);
	while (i < str_length)
	{
		value = value + (str[str_length - i - 1] - '0') * ft_pow(10, i);
		i++;
	}
	return (value);
}

// int main(void)
// {
// 	int a = 2;
// 	int b = 10;
// 	char str[] = "123456";
// 	printf ("%d\n", ft_atoi(str));
// 	// printf("%d", ft_pow(a, b));
// }