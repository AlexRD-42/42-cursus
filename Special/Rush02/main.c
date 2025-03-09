/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 00:24:49 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 00:24:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

int main(int argc, char **argv)
{
    char    *str;
    char    *input;
    int     totalsize;

    // int argc = 2;
    // char *argv[] = {"", "123444"};

    totalsize = 0;
    if (argc == 2)
    {
        input = argv[1];
        str = get_dictionary("numbers.dict", &totalsize);
    }
    else if (argc == 3)
    {
        input = argv[2];
        str = get_dictionary(argv[1], &totalsize);
    }
    if (str != NULL && input[0] != '-')
        handle_input(input, str);
    return (0);
}