/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:40:04 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 13:40:04 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    int i;

    i = nb;
    if (nb < 0)
        return (0);
    else if (nb == 0)
        return (1);

    while (i > 1)
        nb = nb * (i-- - 1);

    return (nb);
}

int main ()
{
    printf("%d\n", ft_iterative_factorial(5));
    printf("%d\n", ft_iterative_factorial(0));
    printf("%d\n", ft_iterative_factorial(-5));
}