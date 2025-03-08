/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:23:16 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 14:23:16 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_base(int nbr, char *base)
{
	char	a[11];
	char	i;
	int		sign;

	sign = 1;
	if (nbr == 0)
		write(1, "0", 1);
	else if (nbr < 0)
	{
		write(1, "-", 1);
		sign = -1;
	}
	i = 0;
	while (nbr != 0)
	{
		a[i] = sign * (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
		write(1, &a[i--], 1);
}

// int main(void)
// {
//     int x = -2147483648;

//     ft_putnbr(x);
// }