/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 18:41:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 18:50:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	a[11];
	char	i;
	int		sign;

	sign = 1;
	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		sign = -1;
	}
	i = 0;
	while (nb != 0)
	{
		a[i] = sign * (nb % 10) + '0';
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
		write(1, &a[i--], 1);
}

int main (void)
{
    ft_putnbr(-2147483648);
    write(1, ", ", 2);
    ft_putnbr(2147483647);
    write(1, ", ", 2);
    ft_putnbr(0);
    write(1, ", ", 2);
    ft_putnbr(-0);
    write(1, ", ", 2);
    ft_putnbr(98750);
    write(1, ", ", 2);
    ft_putnbr(-98750);
    write(1, ", ", 2);
    ft_putnbr(-1);
    write(1, ", ", 2);
    ft_putnbr(9);
}