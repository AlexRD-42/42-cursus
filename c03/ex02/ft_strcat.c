/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:21:36 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/08 14:33:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*start;
	
	start = dest;
	while (*dest != 0)
		dest++;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
	return (start);
}

#include <stdio.h>
#include <string.h>

int main(void)
{
    char a[] = "abc";
    char b[] = "def";

    printf("%s\n", a);
    ft_strcat(a, b);
    printf("%s\n", a);
}