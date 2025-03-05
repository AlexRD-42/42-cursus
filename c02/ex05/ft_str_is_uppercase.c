/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 20:01:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:05:36 by adeimlin         ###   ########.fr       */
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

// #include <stdio.h>
// int main(void)
// {
//     char a[] = "AAAA";
//     int flag;
//     flag = ft_str_is_uppercase(a);
//     printf("%d\n", flag);
// }