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

SRCS =	main.c \
		check_map.c \
		check_p_utils.c \
		check_src.c \
		fill_map.c \
		help.c \
		so_long.c \
		check_patch.c \
		check_shape.c \
		check_walls.c \
		functions.c \
		so_long_utils.c \
		./get_line/get_next_line.c \
		./get_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

# -----------------------------------------------------------------------------
# Build Rules
# -----------------------------------------------------------------------------

all: $(NAME)

$(NAME): $(OBJS) so_long.h
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
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