/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:12:05 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 10:34:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*ptr;
	int	i;
	int	n;

	if (min >= max)
		return (NULL);
	n = max - min;
	ptr = (int *) malloc(sizeof(int) * n);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < n)
		ptr[i++] = min++;
	return (ptr);
}


#include <stdio.h>
int main()
{
    int *arr, n;
    int min = -10, max = 10;

    arr = ft_range(min, max);
    n = max - min;

    for (int i=0;i<n;i++)
        printf("%d, ", arr[i]);
}