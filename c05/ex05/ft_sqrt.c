/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:06:06 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 15:06:06 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_sqrt(int nb)
{
    int i;

    i = 0;
    if (nb <= 0)
        return (0);
    else if (nb == 1)
        return (1);
    while (i++ <= nb/2)
        if (i * i == nb)
            return (i);
    return (0);
}

int main()
{
    printf("%d\n", ft_sqrt(1));
    printf("%d\n", ft_sqrt(2));
    printf("%d\n", ft_sqrt(0));
    printf("%d\n", ft_sqrt(4));
    printf("%d\n", ft_sqrt(16));
    printf("%d\n", ft_sqrt(-16));
}