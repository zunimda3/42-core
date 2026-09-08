LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
CPPFLAGS = -I. -Ilibft
SRCS = stack_utils.c \
	   context_init.c \
	   parse_numbers.c \
	   parse_flags.c \
	   operations.c \
	   execute_operation.c \
	   operation_a.c \
	   operation_b.c \
	   operation_combined.c \
	   stack_analysis.c \
	   strategy_dispatch.c \
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
