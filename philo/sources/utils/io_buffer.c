/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:35:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/29 14:12:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>

size_t	ft_strlen(const char *str);

#define FT_BUFFER_SIZE 16384

// writev, ft_error, ft_write

// Returns NULL on full copy, or the pointer array for incomplete copies
const
char	**ft_strvcpy(char **restrict wdst, const char **restrict vec, char *restrict end)
{
	const char *restrict	src;
	char *restrict			dst;
	size_t					length;
	size_t					space_left;

	dst = (char *restrict)*wdst;
	while (*vec != NULL)
	{
		src = (const char *restrict)*vec++;
		length = ft_strlen(src) + (*vec == NULL);
		while (length > 0)
		{
			if (dst >= end)
				return (vec - 1);
			space_left = (size_t)(end - dst);
			if (length < space_left)
				space_left = length;
			length -= space_left;
			while (space_left-- > 0)
				*dst++ = *src++;
			*wdst = dst;
			vec[-1] = src;
		}
	}
	return (NULL);
}

ssize_t	ft_writev(int fd, const char **vec, char endl)
{
	char		buffer[FT_BUFFER_SIZE];
	ssize_t		bytes_written;
	ssize_t		bytes_total;
	const char	**src = vec;
	char		*dst;

	if (vec == NULL || *vec == NULL)
		return (-1);
	bytes_total = 0;
	dst = buffer;
	src = ft_strvcpy(&dst, src, buffer + FT_BUFFER_SIZE);
	while (src != NULL)
	{
		bytes_written = write(fd, buffer, (size_t)(dst - buffer));
		if (bytes_written < 0)
			return (-1);
		bytes_total += bytes_written;
		dst = buffer;
		src = ft_strvcpy(&dst, src, buffer + FT_BUFFER_SIZE);
	}
	dst[-1] = endl;
	bytes_written = write(fd, buffer, (size_t)(dst - buffer - (endl == 0)));
	if (bytes_written < 0)
		return (-1);
	return (bytes_total + bytes_written);
}
