/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:19:28 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:31:06 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	flag;

	flag = 1;
	while (*str != 0 && flag == 1)
	{
		if (!(*str >= 32 && *str <= 126))
			flag = 0;
		str++;
	}
	return (flag);
}

// #include <stdio.h>
// int main(void)
// {
//     char a[] = {'a', 'b', 'c', 0};
//     int flag;
//     flag = ft_str_is_printable(a);
//     printf("%d\n", flag);
// }