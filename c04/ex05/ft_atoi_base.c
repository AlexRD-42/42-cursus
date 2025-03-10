/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:43:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 14:43:31 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parse_base(char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (str[++i] != 0)
		if (str[i] == ' ' || str[i] == '+' || str[i] == '-' || str[i] == '\t')
			return (-1);
		else if (str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
			return (-1);
	if (i <= 1)
		return (-1);
	k = 0;
	while (k < i)
	{
		j = -1;
		while (++j < i)
			if (str[k] == str[j] && k != j)
				return (-1);
		k++;
	}
	return(i);
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

int	ft_find(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
int ft_atoi_base(char *str, char *base)
{
    int i;
	int	j;
    int sign;
    int num;

    i = 0;
    sign = 1;
    num = 0;
    while (str[i] != 0 && (ft_find(base, str[i]) == -1))
		if (str[i++] == '-')
			sign *= -1;
	j = i;
	while (str[i] != 0 && (ft_find(base, str[i]) != -1))
		i++;
	while (str[j] != 0 && (ft_find(base, str[j]) != -1))
	{
		if (ft_find(base, str[j]) <= -1 || ft_parse_base(base) == -1)
			return (0);
		num += ft_find(base, str[j]) * ft_pow(ft_parse_base(base), i - j - 1);
		j++;
	}
    return (sign * num);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi_base("1111", "01"));
	printf("%d\n", ft_atoi_base("af", "0123456789"));
	printf("%d\n", ft_atoi_base("", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("  31b2", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("1111", "01"));
	printf("%d\n", ft_atoi_base("1111", "01"));
	
}