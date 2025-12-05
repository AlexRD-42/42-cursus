# Configuration ------------------------------- #
NAME = philo
BONUS_NAME = philo_bonus
BUILD_PATH = build
INC_PATH = includes
OBJ_PATH = $(BUILD_PATH)/obj
BIN = $(BUILD_PATH)/$(NAME)
BONUS_BIN = $(BUILD_PATH)/$(BONUS_NAME)
VPATH = sources sources/utils sources/tests sources/philo sources/philo_bonus

# Files --------------------------------------- #
LIBS =
SRCS = io.c memory.c string.c input_parsing.c loop.c main.c forks.c monitor.c
OBJS = $(addprefix $(OBJ_PATH)/, $(SRCS:.c=.o))
BONUS_SRCS = io.c memory.c string.c input_parsing.c loop.c main_bonus.c forks_bonus.c monitor_bonus.c
BONUS_OBJS = $(addprefix $(OBJ_PATH)/, $(BONUS_SRCS:.c=.o))

# Flags --------------------------------------- #
CC = clang
CFLAGS = -Wall -Wextra $(addprefix -I,$(INC_PATH)) -flto -fstrict-aliasing -pthread
LFLAGS =
DEBUG = -g -Wpedantic -Wcast-qual -Wfloat-equal -Wswitch-default -Wsign-conversion
SANITIZERS = -fsanitize=address,undefined,leak -fno-omit-frame-pointer
FAST = -march=native -O3 -ffast-math

# Pattern Rule -------------------------------- #
$(OBJ_PATH)/%.o: %.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@

# Linking Rules ------------------------------- #
$(BIN): $(OBJS) | $(BUILD_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LIBS) $(LFLAGS)

$(BONUS_BIN): $(BONUS_OBJS) | $(BUILD_PATH)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJS) $(LIBS) $(LFLAGS)

# Directory Rule ------------------------------ #
$(OBJ_PATH):
	@mkdir -p $@
$(BUILD_PATH):
	@mkdir -p $@

# Phonies ------------------------------------- #
all: $(BIN) $(BONUS_BIN)

bonus: $(BONUS_BIN)

debug: CFLAGS += $(DEBUG) $(SANITIZERS)
debug: clean $(BIN)

fast: CFLAGS += $(FAST)
fast: clean $(BIN)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(BIN) $(BONUS_BIN)

re: fclean all

.PHONY: all clean fclean re fast debug bonus
