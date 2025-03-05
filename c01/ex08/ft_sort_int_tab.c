/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:43:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/01 18:25:21 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (*(tab + i) < *(tab + j))
			{
				temp = *(tab + i);
				*(tab + i) = *(tab + j);
				*(tab + j) = temp;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{

	int a[] = {1, 4, 5, 2, 3, 7, 9, 13, -1, -5};
	
	ft_sort_int_tab(&a[0], 10);


	for (int i=0;i<10;i++)
		printf("%d,", a[i]);
}
