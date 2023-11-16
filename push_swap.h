#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "libft/libft.h"

# define ERROR_MESSAGE "Invalid entry. Please enter a valid number. \n INT_MIN < Number < INT_MAX\n"
# define ERROR_ARGS "No arguments found\n"

typedef struct s_stack {
    int content;
    struct s_stack *next;
} t_stack;

//init
void	putstr_fd(char *s, int fd);
void	error_handle();
int     check_input(char **str);
void    start_stack(char **str);
char	**parse_args(int arg_count, char **args);
int		check_repetition(t_stack *a, int nbr);
void	print_stack(t_stack	*a);
void	ft_init_stack(t_stack **a, char	**str);

//Rules
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);




//stack utils
t_stack *ft_stack_new(int content);
void 	ft_stack_add_back(t_stack **lst, t_stack *newnode);
void	ft_stack_delone(t_stack *lst, void (*del)(int));
void 	ft_stack_clear(t_stack **lst, void (*del)(int));