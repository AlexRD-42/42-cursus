/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:30:37 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/26 19:31:23 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;
	int i = 0;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	
	*dest = '\0';
	return start;
}

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