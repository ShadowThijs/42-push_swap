NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

MAIN_FILE =	push_swap.c

LIBFT_FOLDER = libft
LIBFT_NAME = libft.a
OPS_FOLDER = ops
OPS_NAME = libpushswap.a

all: $(NAME)

$(NAME):
	@make -C $(LIBFT_FOLDER)
	@make -C $(OPS_FOLDER)
	$(CC) $(MAIN_FILE) $(LIBFT_FOLDER)/$(LIBFT_NAME) $(OPS_FOLDER)/$(OPS_NAME) -o $(NAME)

clean:
	@make clean -C $(LIBFT_FOLDER)
	@make clean -C $(OPS_FOLDER)

fclean:
	@make fclean -C $(LIBFT_FOLDER)
	@make fclean -C $(OPS_FOLDER)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
