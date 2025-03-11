/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:45:16 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 19:14:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	k;

	k = 1;
	if (argc > 1)
	{
		while (k < argc)
		{
			i = 0;
			while (argv[k][i] != 0)
			{
				write(1, &argv[k][i], 1);
				i++;
			}
			write(1, "\n", 1);
			k++;
		}
	}
	return (0);
}
