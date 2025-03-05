/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:17:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 19:30:15 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>
// int main(void)
// {
// 	int a = 9, b = 2, div = 0, mod = 0;
// 	printf("(%d %d %d %d)", a, b, div, mod);
// 	ft_div_mod(a,b,&div,&mod);
//         printf("(%d %d %d %d)", a, b, div, mod);
// }