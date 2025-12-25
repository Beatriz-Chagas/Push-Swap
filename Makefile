NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -I.

SRC_DIR		= src
OBJ_DIR		= obj
LIBFT_DIR	= libft

SRCS		= \
	main.c \
	operations/operations.c \
	operations/swap.c \
	operations/push.c \
	operations/rotate.c \
	operations/reverse_rotate.c \
	sort/sort_small.c \
	sort/sort.c \
	stack_init.c \
	stack_utils.c\
	parsing/parse.c\
	median_utils.c\
	execute_cost.c

SRCS		:= $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT		= $(LIBFT_DIR)/libft.a


all: $(LIBFT) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)


clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
