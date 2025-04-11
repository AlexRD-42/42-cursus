/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 18:20:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	byte;

	byte = (unsigned char) (c & 0x7F);
	if (byte == 0)
		return ((char *)(str + ft_strlen(str)));
	while (*str != 0)
	{
		if (*str == byte)
			return ((char *) str);
		str++;
	}
	return (NULL);
}
