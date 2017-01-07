# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdesmare <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/11 10:38:56 by jdesmare          #+#    #+#              #
#*   Updated: 2017/01/07 21:46:41 by jdesmare         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc $(FLAGS)

FLAGS = -Wall -Werror -Wextra

INCLUDES = ./includes/

SRC =	main.c						\
		ft_fractol.c				\
		ft_julia.c					\
		ft_mandelbrot.c				\
		ft_init.c					\
		ft_key_event.c				\
		ft_expose_hook.c			\
		ft_init_image.c				\
		ft_destroy_image.c			\
		ft_set_colors.c				\
		ft_pixel_put.c				\
		ft_mouse_event.c			\
		ft_mouse_move.c				\
		ft_burningship.c			\
		ft_frog.c					\
		ft_colors.c					\
		ft_colors2.c				\
		ft_colors3.c				\
		ft_brain.c					\
		ft_star.c					\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft/
	@$(CC) -I$(INCLUDES) -c $(SRC)
	@$(CC) -L./libft/ -lft $^ -o $@ -lmlx -framework OpenGL -framework Appkit
	@echo "$(NAME) created successfully"

%.o: %.c
	@$(CC) -o $@ -c $<

clean:
	@make clean -C ./libft/
	@echo "Erasing .o files in Fract'ol..."
	@rm -f $(OBJ)
	@echo "Done."

fclean: clean
	@make fclean -C ./libft/
	@echo "Erasing $(NAME)..."
	@rm -f $(NAME)
	@echo "Done."

re: fclean all clean

.PHONY: all, clean, fclean, re
