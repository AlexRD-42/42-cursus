/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:29:06 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 16:30:56 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strncat(char *dest, char *src, unsigned int nb)
{
    while (*dest != 0)
        dest++;

    while (*src != 0 && nb > 0)
    {
        *dest = *src;
        dest++;
        src++;
        nb--;
    }
    *dest = 0;

    return dest;
}

int main(void)
{
    char a[] = "abc";
    char b[] = "defg";

    printf("%s\n", a);
    ft_strncat(a, b, 2);
    printf("%s\n", a);
}