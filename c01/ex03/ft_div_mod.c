/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:36:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/26 13:40:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a/b;
	*mod = a%b;
}

int main(void)
{
	int a = 9, b = 2, div = 0, mod = 0;
	
	printf("(%d %d %d %d)", a, b, div, mod);
	ft_div_mod(a,b,&div,&mod);
        printf("(%d %d %d %d)", a, b, div, mod);
}
