/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:23:50 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 18:51:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	val;

	if (n >= 0)
		val = 'P';
	else
		val = 'N';
	write(1, &val, 1);
}

int main (void)
{
	ft_is_negative(3);
	ft_is_negative(-1);
}