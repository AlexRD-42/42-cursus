/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 11:07:58 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/23 12:30:33 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	ft_read(int fd, char *buffer, t_pointers *ptr, t_string *str)
{
	ssize_t	bytes_read;

	bytes_read = (ptr->diff >= BUFFER_SIZE);
	if (*buffer == 0 || ptr->pos >= ptr->end)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(str->data);
			str->data = NULL;
		}
		else
		{
			ptr->pos = buffer;
			ptr->end = buffer + bytes_read;
		}
	}
	return (bytes_read);
}

uint8_t	ft_init(int fd, char *buffer, t_pointers *ptr, t_string *str)
{
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (1);
	str->data = NULL;
	str->len = 0;
	ptr->pos = buffer;
	ptr->end = buffer + BUFFER_SIZE;
	ptr->diff = BUFFER_SIZE;
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = {0};
	t_pointers	ptr;
	t_string	str;

	if (ft_init(fd, buffer, &ptr, &str) == 1)
		return (NULL);
	while (ft_read(fd, buffer, &ptr, &str) > 0)
	{
		while (ptr.pos < ptr.end && *(ptr.pos) != '\n' && *(ptr.pos) != 0)
			ptr.pos++;
		ptr.pos += (ptr.pos < ptr.end && *(ptr.pos) == '\n');
		ptr.diff = ptr.pos - buffer;
		str.data = ft_realloc(str.data, str.len, str.len + ptr.diff + 1);
		if (str.data == NULL)
			break ;
		ft_strlcpy(str.data + str.len, buffer, ptr.diff + 1);
		str.len += ptr.diff;
		ptr.end -= ptr.diff;
		ft_memcpy(buffer, ptr.pos, ptr.end - buffer);
		*(ptr.end) = 0;
		if (*(str.data + str.len - (str.len > 0)) == '\n')
			break ;
	}
	return (str.data);
}
