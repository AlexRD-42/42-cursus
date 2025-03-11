/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:15:28 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 17:37:47 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

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

int main()
{
    printf("%d\n", ft_is_prime(-1));
    printf("%d\n", ft_is_prime(0));
    printf("%d\n", ft_is_prime(1));
    printf("%d\n", ft_is_prime(2));
    printf("%d\n", ft_is_prime(3));
    printf("%d\n", ft_is_prime(7));
    printf("%d\n", ft_is_prime(13));
    printf("%d\n", ft_is_prime(15485863));
}