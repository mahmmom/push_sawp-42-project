#include "push_swap.h"

void	print_stack(t_stack	*a)
{
	while ((a) != NULL)
	{
		printf("[%ld]\n", (long)(a)->content);

		(a) = (a)->next;
	}
}

void	ft_init_stack(t_stack **a, char **str)
{
	int		i;
	long	num;
	t_stack	*tmp;
	t_stack *head_copy;

	head_copy = *a;
	if (!str)
	{
		// error handle
	}
	i = 0;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		tmp = (t_stack*)malloc(sizeof(*tmp));
		tmp->content = num;
		tmp->next = NULL;
		ft_stack_add_back(a, tmp);
		print_stack(*a);
		//(*a) = head_copy;
		i++;
	}
}

/*
while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			// error_handle()
		if (check_repetition(*a, (int)num))
				// error_handle()
		fill_stack(*a, num);
		i++;
	}
*/