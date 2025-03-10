/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:14:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 14:25:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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

int ft_atoi(char *str)
{
    int i;
	int	j;
    int sign;
    int num;

    i = 0;
    sign = 1;
    num = 0;
    while (str[i] != 0 && !(str[i] >= '0' && str[i] <= '9'))
		if (str[i++] == '-')
			sign *= -1;
	j = i;
	while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[j] != 0 && (str[j] >= '0' && str[j] <= '9'))
	{
		num += (str[j] - '0') * ft_pow(10, i - j - 1);
		j++;
	}
    return (sign * num);
}

// int ft_atoi(char *str)
// {
// 	int i;
// 	int sign;
// 	int num;

// 	i = 0;
// 	sign = 1;
// 	num = 0;
// 	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
// 		str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
// 		i++;
// 	while (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign *= -1;
// 		i++;
// 	}
// 	while (str[i] >= '0' && str[i] <= '9')
// 	{
// 		num = (num * 10) + (str[i] - '0');
// 		i++;
// 	}
// 	return (num * sign);
// }

#include <stdio.h>
int main(void)
{
	printf ("%d\n", ft_atoi("--12345b6"));
	printf ("%d\n", ft_atoi("---12345b6"));
	printf ("%d\n", ft_atoi(" ---+- -+1234ab567"));
	printf ("%d\n", ft_atoi("12345"));
	printf ("%d\n", ft_atoi("0"));
	printf ("%d\n", ft_atoi("-0"));
	printf ("%d\n", ft_atoi("-2147483648"));
	printf ("%d\n", ft_atoi("2147483647"));
	printf ("%d\n", ft_atoi(""));
}