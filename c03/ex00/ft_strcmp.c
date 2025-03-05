/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 15:54:40 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/05 21:19:14 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	while ((*s1 != 0 && *s2 != 0))
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

// int main(void)
// {
//     char s1[] = "aabc";
//     char s2[] = "abcd";

//     printf ("%d, ", ft_strcmp(s1, s2));
//     printf ("%d\n", strcmp(s1, s2));
// }