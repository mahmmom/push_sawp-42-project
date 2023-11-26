#include "push_swap.h"

int	ft_stack_size(t_stack **lst)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = (*lst);
	while (temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;
	int	highest;

	if (!stack)
		return (NULL);
	max = NULL;
	highest = stack->content;
	while (stack)
	{
		if (stack->content >= highest)
		{
			highest = stack->content;
			max = stack;
		}
		stack = stack->next;
	}
	return (max);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;
	int	lowest;

	if (!stack)
		return (NULL);
	min = NULL;
	lowest = stack->content;
	while (stack)
	{
		if (stack->content < lowest)
		{
			lowest = stack->content;
			min = stack;
		}
		stack = stack->next;
	}
	return (min);
}

void ft_stack_add_back(t_stack **lst, t_stack *newnode)
{
	t_stack *current;

	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
}

