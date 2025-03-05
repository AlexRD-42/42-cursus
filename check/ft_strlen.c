/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:17:29 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 19:31:57 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str >= 33 && *str <= 126)
	{
		i++;
		str++;
	}
	return (i);
}

// #include <stdio.h>
// int main(void)
// {
// 	char str[4] = {'a', 'b', 'c', 'd'};
// 	int i;
// 	i = ft_strlen(&str[0]);
// 	printf("%d", i);
// }
