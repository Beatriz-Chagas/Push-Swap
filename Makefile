NAME = push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= \
	push_swap.c \
	init/parse_args.c \
	init/validate_args.c \
	init/init_stack.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse_rotate.c \
	sort/index_stack.c \
	sort/sort_small.c \
	sort/sort_big.c \
	utils/stack_utils.c \
	utils/errors.c

SRCS        = $(addprefix $(SRC_DIR)/, $(SRC))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --------------------------------------------------------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/init
	@mkdir -p $(OBJ_DIR)/operations
	@mkdir -p $(OBJ_DIR)/sort
	@mkdir -p $(OBJ_DIR)/utils
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re