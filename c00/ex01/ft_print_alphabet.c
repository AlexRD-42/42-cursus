/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:17:59 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 15:23:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void ft_print_alphabet(void)
{
	char	a;
	
	a = 'a';
	while (a <= 'z')
	{
		write(1, &a, 1);
		a++;
	}
}

int main (void)
{
	ft_print_alphabet();
}
