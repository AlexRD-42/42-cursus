/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:05:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/22 15:22:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t length)
{
	unsigned char	*restrict			udst;
	const unsigned char	*restrict		usrc = src;

	udst = dst;
	while (length--)
		*udst++ = *usrc++;
	return (dst);
}

int64_t	ft_atoi(const char *str)
{
	int64_t	number;
	int64_t	sign;

	number = 0;
	sign = -1;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
	{
		str++;
		sign = -sign;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
		number = number * 10 - (*str++ - '0');
	return (sign * number);
}
