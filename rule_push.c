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

void	pa(t_stack **a, t_stack **b, bool print)
{
	push(b, a);
	if (!print)
		write(1, "pa\n", 3);
}
void	pb(t_stack **a, t_stack **b, bool print)
{
	push(a, b);
	if (!print)
		write(1, "pb\n", 3);
}
