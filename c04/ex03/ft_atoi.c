/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 19:14:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 12:06:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] != 0 && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

#include <stdio.h>
int main(void)
{
	printf ("%d\n", ft_atoi("--12345b6"));
	printf ("%d\n", ft_atoi("---12345b6"));
	printf ("%d\n", ft_atoi(" ---+-b-+1234ab567"));
	printf ("%d\n", ft_atoi("1b2345"));
	printf ("%d\n", ft_atoi("0"));
	printf ("%d\n", ft_atoi("-0"));
	printf ("%d\n", ft_atoi("-2147483648"));
	printf ("%d\n", ft_atoi("2147483647"));
	printf ("%d\n", ft_atoi(""));
}