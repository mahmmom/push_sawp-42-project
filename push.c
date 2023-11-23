#include "push_swap.h"

static void	push(t_stack **src,	t_stack **dest)
{
	t_stack *temp;

	if (!*src)
		return ;
	temp = *src;
	(*src) = (*src)->next;
	temp->next = *dest;
	(*dest) = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pa\n", 3);
}
void	pb(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pb\n", 3);
}
