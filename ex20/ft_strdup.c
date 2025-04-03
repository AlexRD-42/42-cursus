/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:53:13 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/03 10:53:13 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	unsigned int	i;
	char			*str;

	i = 0;
	while (src[i] != 0)
		i++;
	str = (char *) malloc(i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = 0;
	while (--i > 0)
		str[i] = src[i];
	str[i] = src[i];
	return (str);
}