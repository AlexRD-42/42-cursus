/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:15:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 17:17:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
    int i;
    
    i = 0;
    while (*str != 0)
    {
        str++;
        i++;
    }
    return i;
}

int main(void)
{
    char a[] = "abcdef";

    printf ("%d", ft_strlen(a));
}