/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:34:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 19:25:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	(void)argc;
	while (argv[0][i] != 0)
	{
		i++;
	}
	write(1, &argv[0][j], i - j);
	write(1, "\n", 1);
	return (0);
}
