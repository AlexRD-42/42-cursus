/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:17:03 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 13:32:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

#include <stdio.h>
int main (void)
{
	int a = 2;
	int b = 4;

	printf("(%d, %d) ", a,b);
	ft_swap(&a, &b);
	printf("(%d, %d)", a,b);
}
