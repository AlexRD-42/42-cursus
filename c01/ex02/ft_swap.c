/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:31:59 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/26 13:36:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

int main (void)
{
	int a = 2;
	int b = 4;

	printf("(%d, %d) ", a,b);
	ft_swap(&a, &b);
	printf("(%d, %d)", a,b);

}
