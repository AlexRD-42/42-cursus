/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:42:39 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/28 12:33:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	func(int n)
{
	int		k;
	char	comb[11];

	k = 0;
	comb[10] = ',';
	while (k < n)
	{
		comb[k] = '0' + k;
		k++;
	}
	k--;
	while (!(comb[n - 1] == '9' && comb[0] == (10 - n + '0')))
	{
		while (comb[k] == (10 - n + k + '0') && k > 0)
			k--;
		comb[k]++;
		while (k < (n - 1))
		{
			comb[k + 1] = comb[k] + 1;
			k++;
		}
		write(1, &comb[0], n);
		if (!(comb[n - 1] == '9' && comb[0] == (10 - n + '0')))
			write(1, &comb[10], 1);
	}
}

int	main(void)
{
	func(3);
}
