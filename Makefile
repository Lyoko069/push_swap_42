NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I.

SRC			= main.c args.c split.c parser_arg.c flags.c stack_utils.c index.c \
			  disorder.c stack_info.c sort.c sort_small.c sort_simple.c \
			  sort_chunk.c sort_radix.c sort_low.c sort_low_utils.c swap.c \
			  push.c rotate.c rrotate.c bench.c bench_utils.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
