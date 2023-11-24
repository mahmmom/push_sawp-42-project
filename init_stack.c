#include "push_swap.h"

void	print_stack(t_stack	*a)
{
	while ((a) != NULL)
	{
		printf("[%ld]\n", (long)(a)->content);

		(a) = (a)->next;
	}
}
static t_stack	*find_last(t_stack	*head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

static void	fill_stack(t_stack **a, int num)
{
	t_stack	*tmp;
	t_stack	*last_node;

	if (!a)
		return;
	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		return;
	tmp->content = num;
	tmp->next = NULL;
	if (!(*a))
	{
		*a = tmp;
		tmp->prev = NULL;
	}
	else
	{
		last_node = find_last(*a);
		last_node->next = tmp;
		tmp->prev = last_node;
	}
	//ft_stack_add_back(a, tmp);
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