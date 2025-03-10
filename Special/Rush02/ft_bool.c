/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:28:11 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 00:28:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_bool.h"

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int	is_alpha(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}


// bit 0000dcba (d = ALPHA, c = alpha, b = digit, a = space)
int	ft_parse_char(char c)
{
	int	value;

	value = 0;
	if (c == ' ' || c == '\t')
		value += 1;
	else if (c >= '0' && c <= '9')
		value += 2;
	else if (c >= 'a' && c <= 'z')
		value += 4;
	else if (c >= 'A' && c <= 'Z')
		value += 8;
}