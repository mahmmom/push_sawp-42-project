#include "push_swap.h"

static void	swap(t_stack	**stack)
{
	t_stack *temp;

	if (!stack)
		return;
	temp = (*stack);
	(*stack) = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack	**a, t_stack **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}