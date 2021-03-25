CC = gcc
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -g -fsanitize=address
NAME = cub3d

DIR_H = ./includes
DIR_S = ./srcs/
DIR_O = ./

SRC =	ft_init.c				\
		parse/get_next_line.c	\
		parse/parsing_map.c		\
		parse/parsing_unit.c	\
		parse/parsing.c			\
		parse/util.c			\
		ft_key_press.c			\
		ft_img.c				\
		ft_init_img.c			\
		ft_raycasting.c			\
		ft_tex_xy.c				\
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

