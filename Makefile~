#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 13:16:08 by ckrommen          #+#    #+#              #
#    Updated: 2017/10/26 16:18:17 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = filetoarr.c newpiece.c createpieces.c translate.c translatepiece.c placepiece.c isempty.c pickuppiece.c createmap.c countpiece.c tetchecker.c printgrid.c main.c solve.c

FLAGS = -Wall -Wextra -Werror

NAME = fillit

$(NAME):
	gcc $(FLAGS) $(SRCS) -L./ckrommen -lft -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all