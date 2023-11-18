#include "push_swap.h"

static void	rotate(t_stack	**stack)
{
	t_stack *temp;

	if (!stack)
		return;
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = NULL;
	ft_stack_add_back(stack, temp);
}

void	ra(t_stack **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack	**a, t_stack **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}