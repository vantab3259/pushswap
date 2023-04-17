# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 00:03:15 by mudoh             #+#    #+#              #
#    Updated: 2023/04/17 00:37:15 by mudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = pushswap.c \
		command.c \
		command_all.c \
		mouvement.c \
		pile_utils.c \
		pile_utils2.c \
		utils.c \
		verif.c \
		algo.c \
		lst_utils.c
		
OBJS = $(SRC:.c=.o)

CFLAGS = -Wextra -Wall -Wall -g3

CC = cc

PRINTF = ft_printf/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)
	
clean:
	rm -rf $(OBJS)
	make -C ft_printf/ clean

fclean : clean
	rm -rf $(NAME)
	make -C ft_printf/ fclean

re : fclean all

.PHONY: all clean fclean re libft

