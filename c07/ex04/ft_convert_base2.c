/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 12:37:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 19:47:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_parse_base(char *str, int k);
int	ft_find(char *str, char c);
int	ft_parse_number(char *str, char *base, int *i, int *sign);
int	ft_atoi_base(char *str, char *base);

int	ft_parse_base(char *str, int k)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i] != 0)
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (-1);
		if (str[i] == '+' || str[i] == '-')
			return (-1);
	}
	if (i <= 1)
		return (-1);
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
	return (-1);
}

int	ft_parse_number(char *str, char *base, int *i, int *sign)
{
	int	n;

	*i = 0;
	*sign = 1;
	while (str[*i] != 0 && ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32))
		*i += 1;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*sign *= -1;
		*i += 1;
	}
	n = *i;
	while (str[n] != 0 && (ft_find(base, str[n]) != -1))
		n++;
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	sign;
	int	num;
	int	base_length;

	num = 0;
	n = ft_parse_number(str, base, &i, &sign);
	base_length = ft_parse_base(base, 0);
	if (base_length == -1)
		return (0);
	while (i < n)
		num = num * base_length + ft_find(base, str[i++]);
	return (sign * num);
}
