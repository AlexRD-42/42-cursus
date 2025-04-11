#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

int	ft_strlen(char *str);
int ft_atoi(char *str);

void display_error(char *program_name, char *filename)
{
	char *error_msg;
	
	error_msg = strerror(errno);
	write(2, program_name, ft_strlen(program_name));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
}

void display_file_header(char *filename)
{
	write(1, "==> ", 4);
	write(1, filename, ft_strlen(filename));
	write(1, " <==\n", 5);
}

void tail_file(char *filename, int count, int file_count, int current_file)
{
	int fd;
	int bytes_read;
	char *buffer;
	long file_size = 0;
	long pos;
	char single_char;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_error("ft_tail", filename);
		return;
	}
		
	// Get file size
	pos = 0;
	while (read(fd, &single_char, 1) > 0)
		file_size++;
	lseek(fd, 0, SEEK_SET);
		
	// Allocate buffer
	buffer = malloc(file_size + 1);
	if (!buffer)
	{
		close(fd);
		return;
	}
		
	// Read entire file
	bytes_read = read(fd, buffer, file_size);
	close(fd);
		
	if (bytes_read <= 0)
	{
		free(buffer);
		return;
	}
		
	// Display file header if multiple files
	if (file_count > 1)
	{
		if (current_file > 1)
			write(1, "\n", 1);
		display_file_header(filename);
	}
		
	// Display last 'count' bytes
	if (count > file_size)
		count = file_size;
	write(1, buffer + (file_size - count), count);
	free(buffer);
}

int main(int argc, char **argv)
{
	int count = 0;
	int i = 1;
	int file_start_index = 1;
	int file_count = 0;

	// Parse arguments
	if (argc > 3 && strcmp(argv[1], "-c") == 0)
	{
		count = ft_atoi(argv[2]);
		file_start_index = 3;
	}
	else
	{
		write(2, "Invalid usage. Use: ft_tail -c N [file...]\n", 42);
		return (1);
	}
		
	// Count files
	file_count = argc - file_start_index;
		
	// Handle files
	i = 0;
	while (file_start_index + i < argc)
	{
		tail_file(argv[file_start_index + i], count, file_count, i + 1);
		i++;
	}
		
	return (0);
}