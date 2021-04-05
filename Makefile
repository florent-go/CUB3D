NAME = cub3d

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address -I

LIB_DIR = /usr/include

SRCS =	srcs/main.c \
		srcs/ft_map.c \
		srcs/MLX.c \
		srcs/ft_parse.c \
		srcs/get_next_line.c \
		srcs/get_next_line_utils.c \
		srcs/ft_movement.c \
		srcs/fonct.c \
		srcs/keypress.c \
		srcs/ft_put.c \
		srcs/ft_init.c \
		srcs/ft_texture.c \
		srcs/ft_parse_color_reso.c \
		srcs/ft_init2.c \
		srcs/ft_sprites.c \
		srcs/ft_minimap.c \
		srcs/ft_color.c \
		srcs/ft_g_error.c \

CC = gcc

all : $(NAME)

.c.o:
	${CC} ${CFLAGS} -c$< -o ${<:.c=.o}

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) $(LIB_DIR) $(SRCS) -lmlx -framework OpenGL -framework AppKit

clean:
	rm -rf $(OBJ)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
