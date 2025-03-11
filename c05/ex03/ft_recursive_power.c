/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:04:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 17:38:40 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

int main()
{
    printf("%d\n", ft_recursive_power(10, 3));
    printf("%d\n", ft_recursive_power(10, -3));
    printf("%d\n", ft_recursive_power(10, 0));
    printf("%d\n", ft_recursive_power(0, 0));
    printf("%d\n", ft_recursive_power(2, 10));
}