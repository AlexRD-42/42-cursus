/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:58:24 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 16:58:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int k;

    k = argc - 1;
    if (argc > 1)
        while (k >= 1)
        {
            i = 0;
            while(argv[k][i] != 0)
            {
                write(1, &argv[k][i], 1);
                i++;
            }
            write(1, "\n", 1);
            k--;
        }
}