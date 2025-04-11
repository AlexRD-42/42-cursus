/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:31:56 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 17:04:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;

	if (s1 == NULL)
		return (NULL);
	end = (char *) s1 + ft_strlen(s1) - (*s1 != 0);
	while (ft_strchr(set, *s1) != NULL)
		s1++;
	while (end > s1 && ft_strchr(set, *end) != NULL)
		end--;
	if (s1 > end)
		return (ft_strdup(""));
	return (ft_substr(s1, 0, end - s1 + 1));
}
