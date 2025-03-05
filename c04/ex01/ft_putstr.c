/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:23:03 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:27:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str != 0)
	{
		str++;
		i++;
	}
	return (i);
}

void	ft_putstr(char *str)
{
	int	str_length;

	str_length = ft_strlen(str);
	write(1, str, str_length);
}

// int main(void)
// {
//     char str[] = "abcasi102";
//     ft_putstr(str);
// }