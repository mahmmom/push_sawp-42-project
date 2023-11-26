#include "push_swap.h"

void	ready_to_push(t_stack **stack, t_stack *top_node, char s_name)
{
	if (!stack || !*stack || !top_node)
		return;
	while ((*stack)->content != top_node->content)
	{
		if (s_name == 'a')
		{
			if (top_node->above_average)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (s_name == 'b')
		{
			if (top_node->above_average)
				rb(stack, false);
			else
				rrb(stack, false);
		}
		print_stack(*stack);
	}
}

