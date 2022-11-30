# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:49:24 by znichola          #+#    #+#              #
#    Updated: 2022/12/01 00:22:55 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SNAME 	=	main complex map display events fractal \
			colours colours_init_1 colours_init_2 colours_funcs \
			converter
SRC		= $(addsuffix .c, $(SNAME))
OBJ 	= $(SRC:%.c=%.o)

NAME	= fractol

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
# -lm 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : all

clean :
	$(RM) $(NAME) $(OBJ)

fclean : clean
	$(RM) fractol

re: clean all

.PHONY: all bonus clean re


