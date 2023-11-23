#include "push_swap.h"

static void	r_rotate(t_stack	**stack)
{
	t_stack *temp;
	t_stack *head;

	if (!stack)
		return;
	head = (*stack);
	while (head->next != NULL)
	{
		temp = head;
		head = head->next;
	}
	head->next = (*stack);
	temp->next = NULL;
	(*stack) = head;
}

void	rra(t_stack **a)
{
	r_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	r_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack	**a, t_stack **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}