# Name of the library to be created (placed in the root)
NAME = libft.a

# Compiler and compilation flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Iincludes

# Explicit list of source files (only the expected ones)
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

# Corresponding object files will be generated in the root
OBJS = ft_putchar.o ft_swap.o ft_putstr.o ft_strlen.o ft_strcmp.o

# Default rule: 'all' builds the library
all: $(NAME)

# Rule to build the library using the object files.
# 'ar rcs' creates or updates the archive with indexing.
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -c $(SRCS) $(INCLUDES)   # Compile all sources (printing each command)
	ar rcs $(NAME) $(OBJS)                    # Archive object files into libft.a

# Pattern rules for each object file.
ft_putchar.o: srcs/ft_putchar.c includes/ft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c srcs/ft_putchar.c -o ft_putchar.o

ft_swap.o: srcs/ft_swap.c includes/ft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c srcs/ft_swap.c -o ft_swap.o

ft_putstr.o: srcs/ft_putstr.c includes/ft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c srcs/ft_putstr.c -o ft_putstr.o

ft_strlen.o: srcs/ft_strlen.c includes/ft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c srcs/ft_strlen.c -o ft_strlen.o

ft_strcmp.o: srcs/ft_strcmp.c includes/ft.h
	$(CC) $(CFLAGS) $(INCLUDES) -c srcs/ft_strcmp.c -o ft_strcmp.o

# 'clean' removes all object files.
clean:
	rm -f $(OBJS)

# 'fclean' removes object files and the library.
fclean: clean
	rm -f $(NAME)

# 're' performs a full rebuild: fclean then all.
re: fclean all

.PHONY: all clean fclean re