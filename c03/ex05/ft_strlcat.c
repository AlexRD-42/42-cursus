/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:08:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:21:38 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlcat(char *dest, char *src, unsigned int size)
{
	while (*dest != 0)
		dest++;
	while (*src != 0 && size > 0)
	{
		*dest = *src;
		dest++;
		src++;
		size--;
	}
	*dest = 0;
	return (dest);
}

// int main(void)
// {
//     char a[] = "abc";
//     char b[] = "defg";

//     printf("%s\n", a);
//     ft_strlcat(a, b, 2);
//     printf("%s\n", a);
// }