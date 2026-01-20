NAME		= push_swap
CHECKER     = checker

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft

COMMON_SRCS = \
	operations/operations.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse_rotate.c \
	stack_init.c \
	stack_utils.c \
	parsing/parse.c \
	median_utils.c
PUSH_SWAP_SRCS = \
	main.c \
	sort/sort_small.c \
	sort/sort.c \
	execute_cost.c

CHECKER_SRCS = \
	bonus/checker.c \

COMMON_SRCS := $(addprefix $(SRC_DIR)/, $(COMMON_SRCS))
PUSH_SWAP_SRCS := $(addprefix $(SRC_DIR)/, $(PUSH_SWAP_SRCS))
CHECKER_SRCS := $(addprefix $(SRC_DIR)/, $(CHECKER_SRCS))

COMMON_OBJS := $(COMMON_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
PUSH_SWAP_OBJS := $(PUSH_SWAP_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CHECKER_OBJS := $(CHECKER_SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(COMMON_OBJS) $(PUSH_SWAP_OBJS)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "🛠️ Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "📚 Compiling libft..."
	@make -C $(LIBFT_DIR)

bonus: $(LIBFT) $(CHECKER)

$(CHECKER): $(COMMON_OBJS) $(CHECKER_OBJS)
	@echo "🔗 Linking $(NAME)..."
	@$(CC) $(CFLAGS) $^ $(LIBFT) -o $(CHECKER)
	@echo "✅ $(NAME) compiled successfully"

clean:
	@echo "🧹 Removing object files"
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "🗑️ Removing $(NAME)"
	@rm -f $(NAME) $(CHECKER)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
