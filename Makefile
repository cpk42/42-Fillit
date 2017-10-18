#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 13:16:08 by ckrommen          #+#    #+#              #
#    Updated: 2017/10/13 17:57:04 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRCS = filetoarr.c newpiece.c createpieces.c translate.c translatepiece.c placepiece.c isempty.c pickuppiece.c createmap.c countpiece.c

FLAGS = -Wall -Wextra -Werror

NAME = fillit

$(NAME):
	gcc $(FLAGS) $(SRCS) -L./ckrommen -lft -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all