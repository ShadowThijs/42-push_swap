NAME = libpushswap.a
CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = 	dblyll-helpers.c \
		double_op.c \
		op_helpers.c \
		operations.c \
		r_instruct.c \
		rr_instruct.c \
		s_p_instruct.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
