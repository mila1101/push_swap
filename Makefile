NAME = push_swap

SRCS =  push_swap.c rotate.c reverse_rotate.c swap_and_push.c stack_type.c\
		add_list.c free_list.c ft_functions.c ft_split.c bubble_index.c\
		errors.c errors_1.c sorting.c sorting_1.c sorting_radix.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY : all clean fclean re bonus
