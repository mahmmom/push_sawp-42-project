#include "push_swap.h"
#include <stdbool.h>

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (1 == ac || (2 == ac && !av[1][0]))
	{
		putstr_fd(ERROR_ARGS, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	av = parse_args(ac-1, av);
	if (check_input(av))
		ft_init_stack(&a,av);
	//print_stack(a);
	if (!sorted(a))
	{
		if (ft_stack_size(a) == 2)
			sort_2(&a);
		else if (ft_stack_size(a) == 3)
			sort_3(&a);
		else
			start_algorithm(&a, &b);
	}
	//print_stack(a);
	//free_stack();
	return (0);
}
