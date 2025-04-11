/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:21:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/03 18:42:52 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	if (nb < 0 || nb >= 13)
		return (0);
	if (nb <= 2)
		return (1 + (nb == 2));
	if (nb == 3)
		return (6);
	if (nb == 4)
		return (24);
	if (nb == 5)
		return (120);
	if (nb == 6)
		return (720);
	if (nb == 7)
		return (5040);
	if (nb == 8)
		return (40320);
	if (nb == 9)
		return (362880);
	if (nb == 10)
		return (3628800);
	if (nb == 11)
		return (39916800);
	else
		return (479001600);
}
