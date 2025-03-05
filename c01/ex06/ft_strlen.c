/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 14:01:54 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/26 14:08:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;
	i = 0;
	while (*str >= 33 && *str <=126)
	{
		i++;
		str++;
	}
	return i;
}

int main(void)
{
	char str[4] = {'a', 'b', 'c', 'd'};
	int i;

	i = ft_strlen(&str[0]);
	printf("%d", i);
}
