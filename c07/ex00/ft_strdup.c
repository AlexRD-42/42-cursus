/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:45:55 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/11 10:28:00 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	i = 0;
	while (src[i] != 0)
		i++;
	str = (char*) malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = 0;
	while (--i >= 0)
		str[i] = src[i];
	return (str);
}

#include <stdio.h>
int main()
{
    char a[] = "string 1";
    char *b;

    b = ft_strdup(a);

    printf("%s", b);
}