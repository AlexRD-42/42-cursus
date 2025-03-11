/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:27:14 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 10:34:34 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int n;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	n = max - min;
	*range = (int *) malloc(sizeof(int) * n);
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < n)
		(*range)[i++] = min++;
	return (n);
}

#include <stdio.h>
int main()
{
    int *arr;
    int max = 10, min = -10, n;
    n = ft_ultimate_range(&arr, min, max);

    for (int i=0;i<n;i++)
        printf("%d, ", arr[i]);
}

