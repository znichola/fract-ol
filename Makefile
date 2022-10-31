# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:49:24 by znichola          #+#    #+#              #
#    Updated: 2022/10/28 11:04:14 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= main.c complex.c map.c display.c events.c fractal.c
OBJ 	= $(SRC:%.c=%.o)

# CFLAGS	= -I$(INC) -O3 -I.. -g

NAME	= fractol

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@
# -lm 

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
	rm -f $(NAME) $(OBJ)

re: clean all


