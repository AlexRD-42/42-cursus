/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:38:24 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/09 10:40:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_is_prime(int nb)
{
    int i;

    if (nb <= 1)
        return (0);
    else if (nb == 2 || nb == 3)
        return (1);
    else if (nb % 2 == 0 || nb % 3 == 0)
        return (0);
    i = 5;
    while (i * i <= nb)
    {
        if (nb % i == 0 || nb % (i + 2) == 0)
            return (0);
        i += 6;
    }
    return (1);
}

int ft_find_next_prime(int nb)
{
    if (nb <= 1)
        return (2);
    if (nb % 2 == 0)
        nb++;
    while (!ft_is_prime(nb))
        nb += 2;
    return (nb);
}

int main()
{
    printf("%d\n", ft_find_next_prime(-1));
    printf("%d\n", ft_find_next_prime(0));
    printf("%d\n", ft_find_next_prime(1));
    printf("%d\n", ft_find_next_prime(2));
    printf("%d\n", ft_find_next_prime(3));
    printf("%d\n", ft_find_next_prime(8));
    printf("%d\n", ft_find_next_prime(14));  
}