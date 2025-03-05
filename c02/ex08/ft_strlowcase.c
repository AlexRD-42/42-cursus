/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:31:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:06:05 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	while (*str != 0)
	{
		if (*str >= 65 && *str <= 90)
		{
			*str = *str + 32;
		}
		str++;
	}
	return (str);
}

// #include <unistd.h>
// int main(void)
// {
//     char a[] = "abCD123ffzZz";
//     ft_strlowcase(a);
//     write(1, &a, sizeof(a));
//     printf("\n");
// }