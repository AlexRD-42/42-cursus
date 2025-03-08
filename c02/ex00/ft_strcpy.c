/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:30:37 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 13:39:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (start);
}

#include <unistd.h>
int main(void)
{
	char a[4] = {'a', 'b', 'c', 'd'};
	char c[] = "abcd";
	char b[4];
	ft_strcpy(b, a);
	write(1, a, 4);
	printf("\n");	
	write(1, b, 4);
	printf("\n");
}