/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:29:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:30:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *addr1_void, const void *addr2_void, size_t n)
{
	const unsigned char	*addr1;
	const unsigned char	*addr2;

	addr1 = (const unsigned char *) addr1_void;
	addr2 = (const unsigned char *) addr2_void;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*addr1 != *addr2)
			return (*addr1 - *addr2);
		addr1++;
		addr2++;
		n--;
	}
	return (0);
}
