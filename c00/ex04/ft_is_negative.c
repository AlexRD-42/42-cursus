/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:52:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/25 16:58:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_is_negative(int n)
{	
	char val;
	
	if (n>=0)
		val = 'P';
	else
		val = 'N';

	write(1, &val, 1);	
}

int main(void)
{
	ft_is_negative(3);
	ft_is_negative(-1);
}
