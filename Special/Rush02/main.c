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


#include "ft_bool.h"
#include "ft_init.h"
#include "ft_parse.h"
#include "ft_string.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_start(char *num, char **dict);
void	num2str(char d[4], char **dict);

void num2str(char d[4], char **dict)
{
	int	pflag;

	if (d[0] != 0)
	{
		ft_printstr(dict[d[0]], 1);
		ft_printstr(dict[28], 1);
	}
	if (d[1] >= 2)
	{
		ft_printstr(dict[d[1] + 18], 1);
		if (d[2] != 0)
			ft_printstr(dict[d[2]], 1);
	}
	else if (d[1] != 0 || d[2] != 0)
		ft_printstr(dict[d[1] * 10 + d[2]], 1);
	else
		ft_printstr(dict[0], 1);
	if (d[3] > 0)
		ft_printstr(dict[d[3] + 28], 1);
}

void handle_input(char *input, char *str)
{
    char    **dict;
    char    *padded_input;
    
    dict = parse_input(str, ft_strlen(str));
    padded_input = zero_pad(input, ft_strlen(input) % 3);
    ft_start(padded_input, dict);
    ft_free(&dict, &padded_input, &str);
}

char *get_dictionary(char *filename, int *totalsize)
{
    char *str = read_file(totalsize, filename);
    if (str == NULL)
    {
        write(1, "Dict Error\n", 11);
        return (NULL);
    }
    return (str);
}

int main(int argc, char **argv)
{
    char    *str;
    char    *input;
    int     totalsize;

    // int argcc = 2;
    // char *argvv[] = {"", "123444"};

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