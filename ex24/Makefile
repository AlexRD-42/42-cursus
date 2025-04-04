NAME = libft.a
SOURCES = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

INC_DIR = ./includes/
OBJ_DIR = ./obj/
SRC_DIR = ./srcs/

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

OBJECTS = $(patsubst %.c, $(OBJ_DIR)%.o, $(SOURCES))

$(NAME) : $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

all: $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: all clean fclean re