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

int	ft_atoi_base(char *str)
{
	int	str_length;
	int	value;
	int	i;

	i = 0;
	str_length = ft_strlen(str);
	while (i < str_length)
	{
		value = value + (str[str_length - i - 1] - '0') * ft_pow(2, i);
		i++;
	}
	return (value);
}

#include <stdio.h>
int main()
{
	printf("%d", ft_atoi_base("11111"));

}