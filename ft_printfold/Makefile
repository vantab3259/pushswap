# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ranki <ranki@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 11:28:23 by ranki             #+#    #+#              #
#    Updated: 2022/11/24 20:23:01 by ranki            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_flags.c ft_printf.c ft_putnbr_fd.c ft_putstr.c ft_sizechar.c ft_sizehexa.c ft_sizeint.c ft_sizep.c ft_sizestr.c ft_size_unsignedint.c ft_sizeptr.c\

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

$(NAME):
	gcc $(FLAGS) $(SRC) -c 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

all: $(NAME)

clean:	
	
	/bin/rm -f $(OBJ) $(OBJbonus)

fclean: clean
	/bin/rm -f $(NAME)

re:	fclean all

.PHONY : all clean fclean re
