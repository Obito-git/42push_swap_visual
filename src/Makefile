NAME = visual
CC = gcc
SRCS = push_swap_visual.c stack.c print_stacks.c operations.c colors.c utils.c\
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
	
%.o: %.c
	@$(CC) -c -o $@ $<

$(NAME): $(LIBFT_NAME) $(OBJS)
	$(CC) -g3 -fsanitize=address -o $(NAME) $(OBJS)

clean:
	@rm -f $(OBJS)
	@rm -f .*.swp
	@rm -f */.*.swp
	@rm -f a.out

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
