# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mudoh <mudoh@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 13:53:55 by mudoh             #+#    #+#              #
#    Updated: 2023/01/10 22:56:26 by mudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = 	ft_printf.c\
		ft_put_things.c\
		ft_put_thing2.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

OBJ = $(SRC:.c=.o)

HEAD = ./includes/

AR = ar rsc

RM = rm -f

NAME = libftprintf.a

.c.o:
	$(CC) $(CFLAGS) -c -I $(HEAD) $< -o $(<:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME) $(OBJ)
	
re : fclean all

.PHONY : clean fclean all re