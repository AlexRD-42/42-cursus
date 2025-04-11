/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:15:33 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 23:57:39 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	flag;

	flag = 1;
	while (*str != 0 && flag == 1)
	{
		if (!(*str > 96 && *str < 123))
			flag = 0;
		str++;
	}
	return (flag);
}

#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_str_is_lowercase("abcd"));
    printf("%d\n", ft_str_is_lowercase("ABCD"));
    printf("%d\n", ft_str_is_lowercase(" --"));
}