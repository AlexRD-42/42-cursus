/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:57 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 12:45:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

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
	return (i);
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
	return (0);
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

int ft_atoi_base(char *str, char *base)
{
    int i;
	int	j;
    int sign;
    int num;
	int	base_length;

    i = 0;
    sign = 1;
    num = 0;
	base_length = ft_parse_base(base);
    while (str[i] != 0 && !(str[i] >= '0' && str[i] <= '9'))
		if (str[i++] == '-')
			sign *= -1;
	j = i;
	while (str[i] != 0 && (str[i] >= '0' && str[i] <= '9'))
		i++;
	while (str[j] != 0 && (str[j] >= '0' && str[j] <= '9'))
	{
		num += ft_find(base, str[j]) * ft_pow(base_length, i - j - 1);
		j++;
	}
    return (sign * num);
}

int	ft_num_digits(int number, int base)
{
	int	i;

	i = 0;
	while (number != 0)
	{
		number = number / base;
		i++;
	}
	return (i);
}

char	*ft_fill_string(int number, char *num_str, char *base, int num_digits)
{
	int	i;
	int	sign;
	int	base_length;

	i = 0;
	base_length = ft_parse_base(base);
	sign = -1 * (number < 0) + (number > 0);
	if (sign == -1)
	{
		num_str[0] = '-';
		i = 1;
	}
	while (i < ((number < 0) + num_digits))
	{
		num_str[num_digits - i + (number < 0)] = base[sign * (number % base_length)];
		number = number / base_length;
		i++;
	}
	num_str[num_digits + 1 + (number < 0)] = 0;
	return (num_str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*num_str;
	int		number;
	int		base_length[2];
	int		num_digits;

	base_length[0] = ft_parse_base(base_from);
	base_length[1] = ft_parse_base(base_to);
	if (base_length[0] <= 1 || base_length[1] <= 1)
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	num_digits = ft_num_digits(number, base_length[1]);
	num_str = (char *) malloc(num_digits + 1 + (number < 0));
	return (ft_fill_string(number, num_str, base_to, num_digits));
}

#include <stdio.h>
int main()
{
	printf("%s\n", ft_convert_base("4096", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-4096", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-255", "0123456789", "0123456789abcdef"));
}