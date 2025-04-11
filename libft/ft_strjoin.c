/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:33:45 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 17:04:09 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	str_size;
	char	*str;

	if (s1 == NULL || s1 == NULL)
		return (NULL);
	str_size = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *) malloc (str_size);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, str_size);
	ft_strlcat(str, s2, str_size);
	return (str);
}
