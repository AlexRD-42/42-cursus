/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:00:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 17:00:54 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_swap(char **a, char **b)
{
    char    *temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

int ft_strcmp(char *s1, char *s2)
{
    while ((*s1 != 0 && *s2 != 0))
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
    }
    return (*s1 - *s2);
}

void ft_print_str(char *str)
{
    int i;

    i = 0;
    while(str[i] != 0)
    {
        write(1, &str[i], 1);
        i++;
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {
        j = 1;
        while (j < argc)
        {
            if (ft_strcmp (argv[i], argv[j]) < 0)
                ft_swap(&argv[i], &argv[j]);
            j++;
        }
        i++;
    }
    i = 1;
    while (i < argc)
        ft_print_str(argv[i++]);
}