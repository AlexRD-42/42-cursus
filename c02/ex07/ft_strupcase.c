/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:23:13 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/06 15:51:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*start;

	start = str;
	while (*str != 0)
	{
		if (*str >= 97 && *str <= 122)
		{
			*str = *str - 32;
		}
		str++;
	}
	return (start);
}

// #include <unistd.h>
// int main(void)
// {
// 	char a[] = "abcd123ffzZ";
//     int flag;
//     ft_strupcase(a);
//     write(1, &a, sizeof(a));
//     printf("\n");
// }