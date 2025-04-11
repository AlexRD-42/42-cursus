/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:23:16 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 16:27:50 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_space(char c)
{
	if (c == ' ' || c == '+' || c == '-' || c == '\t')
		return (1);
	if (c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_parse_base(char *str)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (str[++i] != 0)
		if (ft_is_space(str[i]))
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

void	ft_putnbr_base(int nbr, char *base)
{
	char	a[11];
	int		i;
	int		base_length;

	base_length = ft_parse_base(base);
	if (base_length <= 0)
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	else if (nbr < 0)
		write(1, "-", 1);
	i = 0;
	while (nbr != 0)
	{
		if (nbr >= 0)
			a[i] = base[(nbr % base_length)];
		else
			a[i] = base[-(nbr % base_length)];
		nbr = nbr / base_length;
		i++;
	}
	while (--i >= 0)
		write(1, &a[i], 1);
}

int main(void)
{
    ft_putnbr_base(-2147483648, "012345 6789");
    ft_putnbr_base(2147483647, "01123456789");
    ft_putnbr_base(0, "");

    ft_putnbr_base(-2147483648, "0123456789");
	write(1, "\n", 1);
    ft_putnbr_base(2147483647, "0123456789");
	write(1, "\n", 1);
    ft_putnbr_base(0, "0123456789");
	write(1, "\n", 1);

    ft_putnbr_base(255, "01");
	write(1, "\n", 1);
    ft_putnbr_base(127, "01");
	write(1, "\n", 1);
    ft_putnbr_base(-255, "01");
	write(1, "\n", 1);
	ft_putnbr_base(-127, "01");
	write(1, "\n", 1);
    ft_putnbr_base(255, "0123456789abcdef");
	write(1, "\n", 1);
	ft_putnbr_base(127, "0123456789abcdef");
	write(1, "\n", 1);

	int	i;
	i = 0;
	while (i < 8)
	{
		ft_putnbr_base(i, "poneyvif");
		write(1, ", ", 2);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (i < 10)
	{
		ft_putnbr_base(i, "0123456789");
		write(1, ", ", 2);
		i++;
	}
	write(1, "\n", 1);
	i = 0;
	while (i < 16)
	{
		ft_putnbr_base(i, "0123456789abcdef");
		write(1, ", ", 2);
		i++;
	}
}