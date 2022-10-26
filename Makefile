# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: znichola <znichola@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/26 18:49:24 by znichola          #+#    #+#              #
#    Updated: 2022/10/26 19:46:16 by znichola         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC 	= main.c
OBJ 	= $(SRC:%.c=%.o)

# CFLAGS	= -I$(INC) -O3 -I.. -g

NAME	= fractol

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


clean:
	rm -f $(NAME) $(OBJ)

re: clean all


