/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:32:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 18:20:43 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t			len;
	unsigned char	byte;

	byte = (unsigned char) (c & 0x7F);
	len = ft_strlen(str);
	if (byte == 0)
		return ((char *)(str + len));
	while (len > 0)
	{
		len--;
		if (str[len] == byte)
			return ((char *) str + len);
	}
	return (NULL);
}
