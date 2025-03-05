/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:56:28 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 13:56:28 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_power(int nb, int power)
{
    int base;

    if (power < 0)
        return (0);
    else if (power == 0)
        return (1);

    base = nb;
    while (power-- > 1)
        nb = nb * base;

    return (nb);
}

int main()
{
    printf("%d\n", ft_iterative_power(10, 3));
    printf("%d\n", ft_iterative_power(10, -3));
    printf("%d\n", ft_iterative_power(10, 0));
    printf("%d\n", ft_iterative_power(0, 0));
    printf("%d\n", ft_iterative_power(2, 10));
}