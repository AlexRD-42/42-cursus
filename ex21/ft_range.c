/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:05:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/03 14:17:15 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	unsigned int	i;
	unsigned int	n;
	int				*array;

	if (min >= max)
		return (NULL);
	n = max - min;
	array = (int *) malloc(n * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}
