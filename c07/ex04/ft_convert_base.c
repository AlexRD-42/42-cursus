/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:45:57 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 21:51:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_parse_base(char *str, int k);
int	ft_find(char *str, char c);
int	ft_parse_number(char *str, char *base, int *i, int *sign);
int	ft_atoi_base(char *str, char *base);

int	ft_num_digits(int number, int base)
{
	int	i;

	if (number == 0)
		return (1);
	i = 0;
	while (number != 0)
	{
		number = number / base;
		i++;
	}
	return (i);
}

void	reverse_string(char *str)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (str[end] != 0)
		end++;
	end--;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

char	*ft_fill_string(int number, char *num_str, char *base, int num_digits)
{
	int	i;
	int	sign;
	int	radix;

	i = 0;
	radix = ft_parse_base(base, 0);
	sign = -1 * (number < 0) + (number >= 0);
	while (i < (num_digits + (number < 0)))
	{
		num_str[i] = base[sign * (number % radix)];
		number = number / radix;
		i++;
	}
	if (sign == -1)
		num_str[i++] = '-';
	num_str[i] = 0;
	reverse_string(num_str);
	return (num_str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*num_str;
	int		number;
	int		radix_old;
	int		radix_new;
	int		num_digits;

	radix_old = ft_parse_base(base_from, 0);
	radix_new = ft_parse_base(base_to, 0);
	if (radix_old <= 1 || radix_new <= 1)
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	num_digits = ft_num_digits(number, radix_new);
	num_str = (char *) malloc(num_digits + 1 + (number < 0));
	if (num_str == NULL)
		return (NULL);
	return (ft_fill_string(number, num_str, base_to, num_digits));
}

#include <stdio.h>
int main()
{
	printf("%s\n", ft_convert_base("4096", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-4096", "0123456789", "0123456789abcdef"));
	printf("%s\n", ft_convert_base("-255", "0123456789", "01234567"));
	printf("%s\n", ft_convert_base("-127", "0123456789", "01"));
	// ft_convert_base("-127", "0123456789", "fff");
	// ft_convert_base("-12x7", "012326789", " aushda");
	// ft_convert_base("12x7", "0123267x879", "123");
}