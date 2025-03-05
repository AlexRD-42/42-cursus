/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:34:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 16:34:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    printf("\n Start\n");
    while(argv[0][i] != 0)
    {
        if (argv[0][i] == 92)
            j = i;
        i++;
    }
    write(1, &argv[0][j+1], i-j-1);
    write(1, "\n", 1);
    printf("End");
}