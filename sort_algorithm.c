#include "push_swap.h"

static t_stack	*get_cheapest(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->lowest_moves)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	push_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_average
		&& cheapest_node->targeted_node->above_average)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_average)
		&& !(cheapest_node->targeted_node->above_average))
		rev_rotate_both(a, b, cheapest_node);
	ready_to_push(a, cheapest_node, 'a');
	ready_to_push(b, cheapest_node->targeted_node, 'b');
	pb(a, b, false);
}

void	push_to_a(t_stack **a, t_stack **b)
{
	ready_to_push(a, (*b)->targeted_node, 'a');
	pa(a, b, false);
}

void	min_of_stack(t_stack **stack)
{
	if (!stack || !*stack)
		return;
	while ((*stack)->content != find_min(*stack)->content)
	{
		if (find_min(*stack)->above_average)
			ra(stack, false);
		else
			rra(stack, false);
	}
}