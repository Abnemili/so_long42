NAME      = so_long
CC        = cc
CFLAGS    = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11

SRCS = \
	src/main.c \
	src/check_map.c \
	src/check_p_utils.c \
	src/check_src.c \
	src/fill_map.c \
	src/help.c \
	src/so_long.c \
	src/check_path.c \
	src/check_shape.c \
	src/check_walls.c \
	src/functions.c \
	src/so_long_utils.c \
	get_line/get_next_line.c \
	get_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
