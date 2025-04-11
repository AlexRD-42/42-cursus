/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:30:53 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/10 16:31:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	str_size;
	char	*new_str;

	str_size = ft_strlen(str) + 1;
	new_str = (char *) malloc(str_size);
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, str, str_size);
	return (new_str);
}
