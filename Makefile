# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:49:24 by znichola          #+#    #+#              #
#    Updated: 2022/12/01 21:03:13 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME 	=	main complex map display events events_2 fractal \
			colours colours_def_1 colours_def_2 colours_funcs \
			converter init display_itterators
SRC		= $(addsuffix .c, $(SNAME))
OBJ 	= $(SRC:%.c=%.o)

NAME	= fractol

%.o: %.c
	$(CC) -Wall -Wextra -Werror  -Imlx -c $< -o $@

all : mlx/libmlx.a $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -lm 

bonus : all

clean :
	$(RM) $(NAME) $(OBJ)

fclean : clean
	$(RM) fractol
	$(MAKE) -C mlx/ clean

re: fclean all

mlx/libmlx.a :
	$(MAKE) -C mlx/ libmlx.a

.PHONY: all bonus clean re


