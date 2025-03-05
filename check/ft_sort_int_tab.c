/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:17:39 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 19:30:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// #include <stdio.h>
// int main(void)
// {
// 	int a[] = {1, 4, 5, 2, 3, 7, 9, 13, -1, -5};
// 	ft_sort_int_tab(&a[0], 10);
// 	for (int i=0;i<10;i++)
// 		printf("%d,", a[i]);
// }
