/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:39:08 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 19:09:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putnbr(int nb)
{
    int x;
    int modVar;
    int num;

    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return;
    }
        
    modVar = 1;
    num = 0;
    if (nb < 0)
    {
        write(1, "-", 1);
        nb = -nb;
    }
    x = nb;
    while (x > 9)
    {
        x = x / 10;
        modVar = modVar * 10;
    }
    while (modVar > 0)
    {
        num = ((nb / modVar) % 10) + '0';
        modVar = modVar / 10;
        write(1, &num, 1);
    }
}

int main (void)
{
    int n = -2147483647;
    ft_putnbr(0);
    printf ("\n");
}