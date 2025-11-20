NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./include -I./libft

# Directories
SRC_DIR = src
LIBFT_DIR = libft
INCLUDE_DIR = include

# Automatically find all source files (exclude main.c)
SRC_FILES = $(shell find $(SRC_DIR) -name '*.c' -not -name 'main.c')
SRC_OBJ = $(SRC_FILES:.c=.o)
SRC_TOTAL = $(words $(SRC_FILES))

# Libft sources (automatically find all .c files)
LIBFT_SRC = $(shell find $(LIBFT_DIR) -name '*.c')
LIBFT_OBJ = $(LIBFT_SRC:.c=.o)
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_TOTAL = $(words $(LIBFT_SRC))

# Progress counter files
LIBFT_PROGRESS = .libft_progress
SRC_PROGRESS = .src_progress

# Colors
GREEN = \033[0;32m
BLUE = \033[0;34m
YELLOW = \033[0;33m
RESET = \033[0m
BOLD = \033[1m

all: $(NAME)

$(NAME): $(LIBFT) $(SRC_OBJ)
	@echo -e "\n$(BLUE)$(BOLD)[3/3]$(RESET) $(GREEN)Linking $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) src/main.c $(SRC_OBJ) $(LIBFT) -o $(NAME)
	@echo -e "$(GREEN)$(BOLD)✓ Build complete: $(NAME)$(RESET)"
	@rm -f $(LIBFT_PROGRESS) $(SRC_PROGRESS)

$(LIBFT): $(LIBFT_OBJ)
	@echo -e "\n$(BLUE)$(BOLD)[2/3]$(RESET) $(YELLOW)Creating libft archive...$(RESET)"
	@ar rcs $(LIBFT) $(LIBFT_OBJ) 2>/dev/null

# Compile libft object files
$(LIBFT_DIR)/%.o: $(LIBFT_DIR)/%.c
	@if [ ! -f $(LIBFT_PROGRESS) ]; then echo "0" > $(LIBFT_PROGRESS); fi
	@COUNTER=$$(cat $(LIBFT_PROGRESS)); \
	COUNTER=$$((COUNTER + 1)); \
	echo $$COUNTER > $(LIBFT_PROGRESS); \
	printf "\r$(BLUE)$(BOLD)[1/3]$(RESET) Compiling libft... [$(GREEN)%2d$(RESET)/$(LIBFT_TOTAL)] %-50s" $$COUNTER "$<"
	@if ! $(CC) $(CFLAGS) -c $< -o $@ 2>/tmp/.make_error_$$$$; then \
		echo ""; cat /tmp/.make_error_$$$$; rm -f /tmp/.make_error_$$$$; exit 1; \
	fi; rm -f /tmp/.make_error_$$$$

# Compile source object files
$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@if [ ! -f $(SRC_PROGRESS) ]; then echo "0" > $(SRC_PROGRESS); fi
	@COUNTER=$$(cat $(SRC_PROGRESS)); \
	COUNTER=$$((COUNTER + 1)); \
	echo $$COUNTER > $(SRC_PROGRESS); \
	printf "\r$(BLUE)$(BOLD)[2/3]$(RESET) Compiling src...   [$(GREEN)%2d$(RESET)/$(SRC_TOTAL)] %-50s" $$COUNTER "$<"
	@if ! $(CC) $(CFLAGS) -c $< -o $@ 2>/tmp/.make_error_$$$$; then \
		echo ""; cat /tmp/.make_error_$$$$; rm -f /tmp/.make_error_$$$$; exit 1; \
	fi; rm -f /tmp/.make_error_$$$$

clean:
	@echo -e "$(YELLOW)Cleaning object files...$(RESET)"
	@rm -f $(LIBFT_OBJ) $(SRC_OBJ)
	@rm -f $(LIBFT_PROGRESS) $(SRC_PROGRESS)
	@echo -e "$(GREEN)✓ Clean complete$(RESET)"

fclean: clean
	@echo -e "$(YELLOW)Removing binaries...$(RESET)"
	@rm -f $(LIBFT) $(NAME)
	@echo -e "$(GREEN)✓ Full clean complete$(RESET)"

re: fclean all

.PHONY: all clean fclean re
