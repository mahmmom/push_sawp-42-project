NAME 			= push_swap

SRC 			= main.c stack_utils.c args_handle.c error_handle.c init_stack.c \
				push.c swap.c rotate.c rrotate.c small_sort.c\

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -Ilibft -g3 -fsanitize=address

all: $(NAME)

$(NAME): libft
	cc $(CFLAGS) $(SRC) libft/libft.a -o $(NAME)

libft:
	cd libft && make

clean:
	$(RM)

fclean:	clean
	$(RM) $(NAME)
	cd libft && make fclean

re:	fclean $(NAME)

.PHONY:	all clean fclean re libft