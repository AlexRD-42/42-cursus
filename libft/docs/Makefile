NAME = libft.a
SOURCES = *.c

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
