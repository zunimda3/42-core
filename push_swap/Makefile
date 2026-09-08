LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -Ilibft
SRCS = ps_lstadd_top.c \
	   ps_lstadd_back.c \
	   ps_lstclear.c \
	   ps_node_new.c \
	   context_init.c \
	   parser.c \
	   parse_flags.c \
	   operations.c \
	   execute_operation.c \
	   operation_a.c \
	   operation_b.c \
	   operation_combined.c \
	   resolve_strategy.c \
	   stack_analysis.c \
	   main.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
