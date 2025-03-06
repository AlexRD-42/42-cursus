/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:08:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/06 15:37:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_size;
	unsigned int	src_size;
	unsigned int	total_size;
	unsigned int	i;

	dest_size = 0;
	src_size = 0;
	i = 0;
	while (dest[dest_size] != 0)
		dest_size++;
	while (src[src_size] != 0)
		src_size++;
	if (dest_size >= size)
		return (size + src_size);
	total_size = size - dest_size - 1;
	while (i < total_size && src[i] != 0)
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = 0;
	return (dest_size + src_size);
}

#include <string.h>
#include <stdio.h>
int main(void)
{
    char a[] = "Ola meu";
    char b[] = "Nome Alex";
	
    printf("%s\n", a);
    ft_strlcat(a, b, 10);
    printf("%s\n", a);
}