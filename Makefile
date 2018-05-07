#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akasamar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/07 17:18:21 by akasamar          #+#    #+#              #
#    Updated: 2018/05/07 17:18:24 by akasamar         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = akasamar.filler

SRC = main.c ft_getinfo.c ft_getbestpoint.c

O = $(SRC:.c=.o)

F =  -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
		gcc $(F) $(SRC) libft/libft.a -o $(NAME)
clean:
		rm -f $(O)
cleanlib:
		make clean -C ./libft/
fcleanlib:
		make fclean -C ./libft/
fclean: clean fcleanlib
		rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean