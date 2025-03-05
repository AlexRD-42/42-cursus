/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:52:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 13:18:38 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i = 0;
    
	while (src[i] != 0 && i < size-1)
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = 0;
    
    return i;
}

int main (void)
{
    
}