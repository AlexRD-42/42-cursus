/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:01:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 23:57:46 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	flag;

	flag = 1;
	while (*str != 0 && flag == 1)
	{
		if (!(*str > 64 && *str < 91))
			flag = 0;
		str++;
	}
	return (flag);
}

#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_str_is_uppercase("abcd"));
    printf("%d\n", ft_str_is_uppercase("ABCD"));
    printf("%d\n", ft_str_is_uppercase(" --"));
}