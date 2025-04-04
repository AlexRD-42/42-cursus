/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:53:13 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/03 15:11:59 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	i;
	unsigned int	n;
	char			*str;

	n = 0;
	while (src[n] != 0)
		n++;
	str = (char *) malloc(n + 1);
	if (str == NULL)
		return (NULL);
	str[n] = 0;
	i = 0;
	while (i < n)
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}
