#include "push_swap.h"

void	start_algorithm(t_stack **a, t_stack **b)
{
	int len_sa;
	t_stack *tmp;

    tmp = *a;
	len_sa = ft_stack_size(tmp);
    if (len_sa-- > 3 && !sorted(*a))
        pb(a, b, false);
    if (len_sa-- > 3 && !sorted(*a))
        pb(a, b, false);
    while (len_sa-- > 3 && !sorted(*a))
    {
        init_stack_a(*a, *b);
        push_to_b(a, b);
    }
    sort_3(a);
    while (*b)
    {
        init_stack_b(*a,*b);
        push_to_a(a,b);
    }
    current_index(*a);
    min_of_stack(a);
}
