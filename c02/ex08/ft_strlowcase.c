/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:31:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 12:33:30 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char *ft_strlowcase (char *str)
{
    while (*str != 0)
    {
        if (*str >= 65 && *str <= 90)
        {
            *str = *str + 32;
        }
        str++;
    }

    return str;
}

int main(void)
{
    char a[] = "abCD123ffzZz";
    
    ft_strlowcase(a);
    write(1, &a, sizeof(a));
    printf("\n");
}