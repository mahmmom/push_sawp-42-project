#include "push_swap.h"

void	print_stack(t_stack	*a)
{
	while ((a) != NULL)
	{
		printf("[%ld]\n", (long)(a)->content);

		(a) = (a)->next;
	}
}

static void	fill_stack(t_stack **a, int num)
{
	t_stack	*tmp;

	tmp = (t_stack*)malloc(sizeof(*tmp));
	tmp->content = num;
	tmp->next = NULL;
	ft_stack_add_back(a, tmp);
}

void	ft_init_stack(t_stack **a, char **str)
{
	int		i;
	long	num;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_handle();
		if (check_repetition(*a, (int)num))
			error_handle();
		fill_stack(a, num);
		i++;
	}
	free_string(str);
}



/*void	ft_init_stack(t_stack **a, char **str)
{
	int		i;
	long	num;
	t_stack	*tmp;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		num = ft_atoi(str[i]);
		tmp = (t_stack*)malloc(sizeof(*tmp));
		tmp->content = num;
		tmp->next = NULL;
		ft_stack_add_back(a, tmp);
		i++;
	}
	//free_string(str);
}*/