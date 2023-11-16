#include "push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (1 == ac || (2 == ac && !av[1][0]))
	{
		putstr_fd(ERROR_ARGS, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	a = NULL;
	b = NULL;
	av = parse_args(ac-1, av);
	if (check_input(av))
		ft_init_stack(&a,av);
	printf("======== stack A ==========\n");
	print_stack(a);
	pb(&a,&b);
	pb(&a,&b);
	pa(&a,&b);
	printf("======== stack A after push ==========\n");
	print_stack(a);
	printf("======== stack B ==========\n");
	print_stack(b);
	return (0);
}





//for(int i = 0; av[i] != NULL; i++)
		//printf("[%s]\n", av[i]);