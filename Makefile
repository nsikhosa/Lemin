# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsikhosa <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/27 12:11:14 by nsikhosa          #+#    #+#              #
#    Updated: 2018/01/27 12:11:19 by nsikhosa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC = free.c main.c move_ants.c path.c queue.c read.c room.c roomtype.c

FLAGS = gcc -Wall -Wextra -Werror

LIBFT = libft/libft.a

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	@$(FLAGS) -o $(NAME) $(SRC) $(LIBFT)

clean:
	make -C libft/ clean

fclean:
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all clean

