/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:59:21 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 15:30:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_print_str(int n, char *str, int flag)
{
	char num;
	char spc;
	n--;
	spc = ',';

	while (n >= 0)
	{
		num = str[n] + '0';
		n--;
		write(1, &num, 1);
	}

	if (flag)
		write(1, &spc, 1);
}

void ft_print_comb(void)
{
	char comb[3];
	int i = 0, k = 0;

	while (i < 3)
	{
		comb[i] = 3-i;
		i++;
	}
	
	i = 0;
	k = 0;
	while (!((comb[2] == 8) && (comb[0] == 9)))
	{
		
		while (comb[k] == (9 - k) && k < 2)
			k++;

		comb[k]++;
		
		while (k > 0)
		{
			comb[k - 1] = comb[k] + 1;
			k--;
		}

		ft_print_str(3, &comb[0], !((comb[2] == 8) && (comb[0] == 9)));
	}
}

int main ()
{
	ft_print_comb();
}
