NAME = gnl.a

SRC = get_next_line.c \
		get_next_line_utils.c

CFLAGS = -Wall -Wextra -Werror

CC = cc

AR = ar rsc

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	
	rm -rf $(OBJ)

fclean:
	rm -rf $(NAME) $(OBJ)
	
re : fclean all

.PHONY : clean fclean all re
