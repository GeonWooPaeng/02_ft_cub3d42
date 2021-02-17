CC = gcc
FLAGS = -Wextra -Werror -Wall 
NAME = cub3d

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC =	main.c


SRCS = $(addprefix $(DIR_S),$(SRC))

OBJS = $(SRCS:.c=.o)

%.o: %.c
	$(CC) $(FLAGS) -c $< -I $(DIR_H) -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./minilibx-linux
	gcc -o $(NAME) -I $(DIR_H) $(OBJS) $(CFLAGS) -lmlx -L./minilibx-linux -lbsd -lXext -lX11 -lm

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	fclean all

.PHONY: clean fclaen all re 

