/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:21:36 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 16:28:26 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// fn appends src to dest, overwriting dest's null terminator
// how to write unsafe code in a nutshell <3

char *ft_strcat(char *dest, char *src)
{
    while (*dest != 0)
        dest++;

    while (*src != 0)
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = 0;

    return dest;
}

int main(void)
{
    char a[] = "abc";
    char b[] = "def";

    printf("%s\n", a);
    ft_strcat(a, b);
    printf("%s\n", a);
}