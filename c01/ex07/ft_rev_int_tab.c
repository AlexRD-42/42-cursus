/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:11:24 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/26 14:39:01 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int arr[size];
	int i;

	i = 0;
	while (i<size)
	{
		arr[i] = *tab; 
		i++;
		tab++;
	}
	
	tab--;
	i = 0;

	while (i<size)
	{
		*tab = arr[i];
		i++;
		tab--;
	}
}

int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};

	ft_rev_int_tab(&a[0], 5);

	for (int i=0;i<5;i++)
		printf("%d,", a[i]);
}
