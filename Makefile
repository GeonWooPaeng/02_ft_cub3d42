CC = gcc
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -g -fsanitize=address
NAME = cub3D

DIR_H = ./includes
DIR_S = ./srcs/
DIR_O = ./

SRC =	ft_init.c				\
		parse/get_next_line.c	\
		parse/parsing_check.c	\
		parse/parsing_map.c		\
		parse/parsing_unit.c	\
		parse/parsing.c			\
		parse/parsing_utils.c	\
		ft_key_press.c			\
		ft_sprite_utils.c		\
		ft_sprite.c				\
		ft_img.c				\
		ft_init_img.c			\
		ft_raycasting.c			\
		ft_tex_xy.c				\
		ft_utils.c				\
		ft_make_bmp.c			\
		main.c					\



SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -I $(DIR_H) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx-linux
	gcc -o $(NAME) -I $(DIR_H) $(OBJS) $(CFLAGS) -lmlx -L./minilibx-linux -lbsd -lXext -lX11 -lm

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclaen all re 

