/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:51:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/26 14:01:16 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	char var;
	while (*str >= 32 && *str<=127)
	{
		write(1, str, 1);
		str++;
	}
}

int main(void)
{
	char str[5] = {'a', 'b', 'c', 0, 'e'};
	ft_putstr(&str[0]);	
}
