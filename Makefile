NAME 			= push_swap

SRC 			= main.c string.c stack_fill.c stack_utils.c args_handle.c\

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