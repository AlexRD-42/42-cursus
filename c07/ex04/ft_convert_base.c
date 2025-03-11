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

char	*ft_fill_string(int number, char *num_str, char *base, int num_digits)
{
	int	i;
	int	sign;
	int	base_length;

	i = 0;
	base_length = ft_parse_base(base, 0);
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

	base_length[0] = ft_parse_base(base_from, 0);
	base_length[1] = ft_parse_base(base_to, 0);
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
	printf("%s\n", ft_convert_base("-255", "0123456789", "0123456789abcdff"));
}