#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ckrommen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/05 13:16:08 by ckrommen          #+#    #+#              #
#    Updated: 2017/11/14 14:31:08 by ckrommen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#


SRCS = piece.c main.c fillit.c map.c tools.c extra.c tetchecker.c

FLAGS = -Wall -Wextra -Werror

NAME = fillit

OBJ = $(SRCS:.c=.o)

LIBFT = ./libft/

$(NAME):
	@$(MAKE) -C $(LIBFT)
	@gcc $(FLAGS) $(SRCS) -L$(LIBFT) -lft -o $(NAME)

all: $(NAME)

clean:
	@$(MAKE) clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT)

re: fclean all