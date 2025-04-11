/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:18:02 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/04 15:14:20 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_initialize(int arg_count, char **arg_value)
{
	int	fd;

	if (arg_count < 2)
	{
		write(2, "File name missing.\n", 19);
		return (-1);
	}
	if (arg_count > 2)
	{
		write(2, "Too many arguments.\n", 20);
		return (-1);
	}
	fd = open(arg_value[1], O_RDONLY);
	if (fd == -1)
		write(2, "Cannot read file.\n", 18);
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		bytes_read;
	char	buffer[64];

	fd = ft_initialize(argc, argv);
	if (fd == -1)
		return (1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, sizeof(buffer));
		if (bytes_read < 0)
		{
			write(2, "Cannot read file.\n", 18);
			close(fd);
			return (1);
		}
		else if (bytes_read > 0)
			write(1, buffer, bytes_read);
	}
	close(fd);
	return (0);
}
