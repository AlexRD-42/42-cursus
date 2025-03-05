/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:38:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/02/27 15:47:06 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i = 0;

	while (*src != '\0' && i < n)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}

    while (i < n)
    {
        *dest = 0;
        dest++;
        i++;
    }

	*dest = '\0';
	return dest;
}

int main(void)
{
	char a[8] = "abcdefg";
	char b[10];
	
	ft_strncpy(b, a, 5);
    write(1, b, 5);
}