/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:30:07 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/03 11:30:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_error(int arg_count)
{
	if (arg_count < 2)
		write(2, "File name missing.\n", 20);
	else if (arg_count > 2)
		write(2, "Too many arguments.\n", 21);
	else
		write(2, "Cannot read file.\n", 19);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		bytesRead;
	char	buffer[512];

	if (argc != 2)
	{
		ft_error(argc);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error(argc);
		return (1);
	}
	while ((bytesRead = read(fd, buffer, 512)) != 0)
		write(1, buffer, bytesRead);
	close(fd);
	return (0);
}