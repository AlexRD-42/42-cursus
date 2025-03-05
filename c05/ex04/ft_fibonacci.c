/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:12:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/04 14:12:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_fibonacci(int index)
{
    if (index < 0)
        return (-1);
    else if (index == 0)
        return (0);
    else if (index == 1)
        return (1);
    return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
}

int main()
{
    printf("%d\n", ft_fibonacci(5));
    printf("%d\n", ft_fibonacci(7));
    printf("%d\n", ft_fibonacci(9));
}