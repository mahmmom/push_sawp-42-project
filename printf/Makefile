NAME 			=	libftprintf.a
SRCS			=	ft_printf.c ft_print_num.c ft_printhex.c ft_printptr.c	\
					ft_printstr.c ft_printunsigned.c ft_putchar.c

OBJS			=$(SRCS:.c=.o)

CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re:fclean all