# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 00:03:15 by mudoh             #+#    #+#              #
#    Updated: 2023/04/18 02:10:54 by mudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker 

SRC = 		mandatory/pushswap.c \
			mandatory/command.c \
			mandatory/command_all.c \
			mandatory/mouvement.c \
			mandatory/pile_utils.c \
			mandatory/pile_utils2.c \
			mandatory/utils.c \
			mandatory/verif.c \
			mandatory/algo.c \
			mandatory/lst_utils.c

SRCBONUS =	bonus/checker.c \
			bonus/command.c \
			bonus/command_all.c \
			bonus/mouvement.c \
			bonus/pile_utils.c \
			bonus/pile_utils2.c \
			bonus/utils.c \
			bonus/verif.c \
			bonus/algo.c \
			bonus/lst_utils.c

OBJS = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

CFLAGS = -Wextra -Wall -Wall -g3

CC = cc

PRINTF = ft_printf/libftprintf.a

GNL = GNL/gnl.a

all: $(NAME)

bonus: $(BONUS)

$(NAME): $(OBJS)
	make -C ft_printf
	$(CC) $(INC) $(CFLAGS)  $(OBJS) $(PRINTF) -o $(NAME)

$(BONUS): $(OBJBONUS)
	make -C ft_printf
	make -C GNL
	$(CC) $(CFLAGS) $(OBJBONUS) $(PRINTF) $(GNL) -o $(BONUS)

clean:
	rm -rf $(OBJS) $(OBJBONUS)
	make -C ft_printf/ clean
	make -C GNL/ clean

fclean : clean
	rm -rf $(NAME) $(BONUS)
	make -C ft_printf/ fclean
	make -C GNL/ fclean


re : fclean all

.PHONY: all clean fclean re libft bonus

