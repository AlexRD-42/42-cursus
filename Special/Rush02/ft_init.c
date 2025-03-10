/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 00:19:40 by adeimlin          #+#    #+#             */
/*   Updated: 2025/03/10 00:19:40 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_init.h"
#include "ft_string.h"
#include "ft_parse.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void handle_input(char *input, char *str)
{
    char    **dict;
    char    *padded_input;
    
    dict = parse_input(str, ft_strlen(str));
    padded_input = zero_pad(input, ft_strlen(input) % 3);
    ft_start(padded_input, dict);
    ft_free(&dict, &padded_input, &str);
}

char *get_dictionary(char *filename, int *totalsize)
{
    char *str = read_file(totalsize, filename);
    if (str == NULL)
    {
        write(1, "Dict Error\n", 11);
        return (NULL);
    }
    return (str);
}

char	*read_file(int *totalsize, char *filename)
{
	char	*buffer;
	char	*str;
	int		fd;
    int		bytesRead;

	*totalsize = 0;
	buffer = (char *) malloc(128);
	fd = open(filename, O_RDONLY);
	if (fd != -1 && buffer != NULL)
		while ((bytesRead = read(fd, buffer, 128)) > 0)
			*totalsize += bytesRead;
	close(fd);
	free(buffer);
	str = (char *) malloc(*totalsize + 1);
	fd = open(filename, O_RDONLY);
	if (fd != -1 && str != NULL)
	{
		bytesRead = read(fd, str, *totalsize);
		str[*totalsize] = 0;
	}
	close(fd);
	return (str);
}

char	*zero_pad(char *str, int n)
{
	int		str_length;

	str_length = ft_strlen(str);
	if (n == 0)
		return (ft_strncpy(str, str_length));
	else if (n == 1)
		return (ft_strncat("00", str, str_length + 2));
	else if (n == 2)
		return (ft_strncat("0", str, str_length + 1));
	return (NULL);
}

void	ft_free(char ***dict, char **input, char **str)
{
	int	i;

	i = 0;
	while (i < 42)
		free((*dict)[i++]);
	free(*dict);
	free(*input);
	free(*str);
}

void	ft_start(char *num, char **dict)
{
	char	d[4];
	int		n;
	int		mag;
	int		i;

	n = ft_strlen(num);
	mag = (n / 3) - 1;
	i = 0;
	while (mag >= 0)
	{
		d[0] = num[i] - '0';
		d[1] = num[i + 1] - '0';
		d[2] = num[i + 2] - '0';
		d[3] = mag;
		i += 3;
		mag--;
		num2str(d, dict);
	}
	write(1, "\n", 1);
}