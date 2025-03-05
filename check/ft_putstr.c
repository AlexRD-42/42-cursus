/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:17:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 19:31:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	char	var;

	while (*str >= 32 && *str <= 127)
	{
		write(1, str, 1);
		str++;
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[5] = {'a', 'b', 'c', 0, 'e'};
// 	ft_putstr(&str[0]);	
// }