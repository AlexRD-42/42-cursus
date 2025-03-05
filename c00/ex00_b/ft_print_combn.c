/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:49:18 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/28 12:38:53 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// first value is 10-n, meaning for n=2 max number is 89
// check for loop end is last index == 10-n, and first index = 9
// if ((comb[n] == 10-n) && (comb[n] == 9))
void ft_print_str(int n, char *str, int flag)
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

void ft_print_combn(int n)
{
	if (n <= 0 || n >= 10)
		return;

	char comb[n];
	int i = 0, k = 0;

	while (i < n)
	{
		comb[i] = n-i;
		i++;
	}
	
	i = 0;
	k = 0;
	while (!((comb[n - 1] == 10 - n) && (comb[0] == 9)))
	{
		
		while (comb[k] == (9-k) && k < n)
			k++;

		comb[k]++;
		
		while (k>0)
		{
			comb[k - 1] = comb[k] + 1;
			k--;
		}

		ft_print_str(n, &comb[0], !((comb[n - 1] == 10 - n) && (comb[0] == 9)));
	}
}

int main ()
{
	int n;
	ft_print_combn(3);
}
