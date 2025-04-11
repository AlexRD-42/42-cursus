/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:47:52 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:34:52 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int32_t n)
{
	int32_t	sign;
	char	str[12];
	char	*ptr;

	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0);
	ptr = str + 11;
	*ptr = 0;
	while (n != 0)
	{
		*(--ptr) = (!sign - sign) * (n % 10) + '0';
		n /= 10;
	}
	if (sign == 1)
		*(--ptr) = '-';
	return (ft_strdup(ptr));
}
