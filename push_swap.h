#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include "libft/libft.h"

# define ERROR_MESSAGE "Error\n"
# define ERROR_ARGS "Error\n"

typedef struct s_stack {
    int 			content;
	int				index;
	int				push_count;
	bool			above_average;
	bool			lowest_moves;
    struct s_stack	*targeted_node;
    struct s_stack	*next;
    struct s_stack	*prev;
} t_stack;

/*
Starting Functions
*/
int     check_input(char **str);
void    start_stack(char **str);
char	**parse_args(int arg_count, char **args);
long	ft_atol(const char *str);
int		check_repetition(t_stack *a, int nbr);
void	ft_init_stack(t_stack **a, char	**str);
void	print_stack(t_stack	*a);

/*
RULES
*/
//swap rules
void	sa(t_stack **a, bool print);
void	sb(t_stack **b, bool print);
void	ss(t_stack	**a, t_stack **b, bool print);
//push rules
void	pa(t_stack **a, t_stack **b, bool print);
void	pb(t_stack **a, t_stack **b, bool print);
//rotate
void	ra(t_stack **a, bool print);
void	rb(t_stack **b, bool print);
void	rr(t_stack	**a, t_stack **b, bool print);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
//rrotate
void	rra(t_stack **a, bool print);
void	rrb(t_stack **b, bool print);
void	rrr(t_stack	**a, t_stack **b, bool print);
void	rev_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);

/*
Sorting Algorthim
*/
//small numbers
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
bool	sorted(t_stack *a);

//big num algorthim
void	start_algorithm(t_stack **a, t_stack **b);
void	init_stack_a(t_stack *a, t_stack *b);
void    current_index(t_stack *stack);
void	set_cheapest(t_stack *stack);
void	ready_to_push(t_stack **stack, t_stack *top_node, char s_name);
void	init_stack_b(t_stack *a, t_stack *b);
void	push_to_b(t_stack **a, t_stack **b);
void	push_to_a(t_stack **a, t_stack **b);
void	min_of_stack(t_stack **stack);


/*
Helping Functions
*/
//stack utils
t_stack *ft_stack_new(int content);
void 	ft_stack_add_back(t_stack **lst, t_stack *newnode);
int		ft_stack_size(t_stack *lst);
t_stack	*find_max(t_stack *stack);
t_stack	*find_min(t_stack *stack);

//error handle
void	free_string(char **str);
void	putstr_fd(char *s, int fd);
void	error_handle();