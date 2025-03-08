/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:10:10 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 13:39:24 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	flag;

	flag = 1;
	while (*str != 0 && flag == 1)
	{
		if (!(*str > 47 && *str < 58))
			flag = 0;
		str++;
	}
	return (flag);
}

#include <stdio.h>
int main(void)
{
    char a[] = "";
    int flag;
    flag = ft_str_is_numeric(a);
    printf("%d\n", flag);
}