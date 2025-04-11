/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:01:31 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 18:50:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	val[5];

	val[2] = ' ';
	i = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			val[0] = i / 10 + '0';
			val[1] = i % 10 + '0';
			val[3] = j / 10 + '0';
			val[4] = j % 10 + '0';
			j++;
			write(1, val, 5);
			if (!(i == 98 && j == 100))
				write(1, ", ", 2);
		}
		i++;
	}
}

int main (void)
{
	ft_print_comb2();
}
