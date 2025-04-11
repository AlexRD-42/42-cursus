#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

#define BUFFER_SIZE 30000

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

void display_error(char *filename)
{
	char *program_name;
	char *error_msg;

	program_name = "ft_cat";
	error_msg = strerror(errno);
	write(2, program_name, ft_strlen(program_name));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
}

void read_from_stdin(void)
{
	int bytes_read;
	char buffer[BUFFER_SIZE];

	while ((bytes_read = read(0, buffer, BUFFER_SIZE)) > 0)
		write(1, buffer, bytes_read);
	if (bytes_read < 0)
		display_error("stdin");
}

void cat_file(char *filename)
{
	int fd;
	int bytes_read;
	char buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		display_error(filename);
		return;
	}
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
		write(1, buffer, bytes_read);
	if (bytes_read < 0)
		display_error(filename);
	close(fd);
}

int main(int argc, char **argv)
{
	int i;

	if (argc == 1)
		read_from_stdin();
	else
	{
		i = 1;
		while (i < argc)
		{
			if (argv[i][0] == '-' && argv[i][1] == '\0')
				read_from_stdin();
			else
				cat_file(argv[i]);
			i++;
		}
	}
	return (0);
}