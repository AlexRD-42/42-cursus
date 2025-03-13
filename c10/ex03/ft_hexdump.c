#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <stdlib.h>

#define BUFFER_SIZE 16

void print_hex(unsigned char byte);
void print_address(unsigned long addr);
void print_hex_line(unsigned char *buffer, int size, int offset);

void display_error(char *program_name, char *filename)
{
	char *error_msg = strerror(errno);
		
	write(2, program_name, strlen(program_name));
	write(2, ": ", 2);
	write(2, filename, strlen(filename));
	write(2, ": ", 2);
	write(2, error_msg, strlen(error_msg));
	write(2, "\n", 1);
}

void hexdump_file(char *filename, int c_flag, unsigned long *total_offset)
{
	int fd;
	int bytes_read;
	unsigned char buffer[BUFFER_SIZE];
	unsigned long offset = *total_offset;
		
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_error("ft_hexdump", filename);
		return;
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (c_flag)
			print_hex_line(buffer, bytes_read, offset);
		offset += bytes_read;
	}
		
	if (bytes_read < 0)
		display_error("ft_hexdump", filename);
		
	close(fd);
	*total_offset = offset;
}

void hexdump_stdin(int c_flag, unsigned long *total_offset)
{
	int bytes_read;
	unsigned char buffer[BUFFER_SIZE];
	unsigned long offset = *total_offset;
		
	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
	{
		if (c_flag)
			print_hex_line(buffer, bytes_read, offset);
		offset += bytes_read;
	}
		
	if (bytes_read < 0)
		display_error("ft_hexdump", "stdin");
		
	*total_offset = offset;
}

int main(int argc, char **argv)
{
	int i = 1;
	int c_flag = 0;
	unsigned long total_offset = 0;
		
	// Check for -C flag
	if (argc > 1 && strcmp(argv[1], "-C") == 0)
	{
		c_flag = 1;
		i++;
	}
		
	// No files provided, read from stdin
	if (i >= argc)
	{
		hexdump_stdin(c_flag, &total_offset);
	}
	else
	{
		// Process each file
		while (i < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				hexdump_stdin(c_flag, &total_offset);
			else
				hexdump_file(argv[i], c_flag, &total_offset);
			i++;
		}
	}
		
	// Print final offset
	if (c_flag)
	{
		print_address(total_offset);
		write(1, "\n", 1);
	}
		
	return (0);
}