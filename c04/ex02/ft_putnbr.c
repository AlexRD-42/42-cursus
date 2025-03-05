/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:26:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 18:55:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void    ft_putnbr(int nb)
{
    int x = nb, count = 0, count2;

    while (x >=1)
    {
        x = x/10;
        count++;
    }
    count2 = count;
    count--;
    char c[count];
    while (count >=0)
    {
        c[count] = nb%10 + '0';
        nb = nb/10;
        count--;
    }
    write(1, &c[0], count2);
}

int main(void)
{
    int x = INT_MIN;
}