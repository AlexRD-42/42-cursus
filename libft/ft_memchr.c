/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:52:02 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *addr_void, int c, size_t n)
{
	const unsigned char	*addr;
	unsigned char		byte;

	byte = (unsigned char) c;
	addr = (const unsigned char *) addr_void;
	while (n > 0)
	{
		if (*addr == byte)
			return ((void *) addr);
		n--;
		addr++;
	}
	return (NULL);
}
