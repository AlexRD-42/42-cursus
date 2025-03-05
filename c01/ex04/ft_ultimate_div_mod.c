/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:45:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/26 13:50:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int mod;
	int div;

	div = *a / *b;
	mod = *a % *b;

	*a = div;
	*b = mod;

}

int main(void)
{
	int a = 9, b = 2;

	ft_ultimate_div_mod(&a,&b);
	printf("%d %d", a, b);
}
