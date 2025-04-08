# -----------------------------------------------------------------------------
# Project Configuration
# -----------------------------------------------------------------------------

NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11

# -----------------------------------------------------------------------------
# Source Files and Objects
# -----------------------------------------------------------------------------

SRCS =  src/main.c \
        src/check_map.c \
        src/check_p_utils.c \
        src/check_src.c \
        src/fill_map.c \
        src/help.c \
        src/so_long.c \
        src/check_patch.c \
        src/check_shape.c \
        src/check_walls.c \
        src/functions.c \
        src/so_long_utils.c \
        ./get_line/get_next_line.c \
        ./get_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

# Adjust OBJS to include the 'src/' prefix for the main object files
OBJS_MAIN = $(patsubst src/%.c,src/%.o,$(filter src/%,$(SRCS)))
OBJS_GNL = $(SRCS:.c=.o)
OBJS_GNL := $(filter ./get_line/%,$(OBJS_GNL))

OBJS = $(OBJS_MAIN) $(OBJS_GNL)

# -----------------------------------------------------------------------------
# Build Rules
# -----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

./get_line/%.o: ./get_line/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# -----------------------------------------------------------------------------
# Cleaning Rules
# -----------------------------------------------------------------------------

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# -----------------------------------------------------------------------------
# Phony Targets (Targets that are not actual files)
# -----------------------------------------------------------------------------

.PHONY: all clean fclean re