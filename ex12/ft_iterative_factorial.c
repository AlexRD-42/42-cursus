/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 12:21:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/02 12:21:31 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_iterative_factorial(int nb)
{
	int	value;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	value = nb;
	while (--nb > 0)
		value *= nb;
	return (value);
}

#include <stdio.h>
int	main(void)
{
	printf("%d", ft_iterative_factorial(0));	
}