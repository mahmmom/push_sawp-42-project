#include "push_swap.h"

void	start_algorithm(t_stack **a, t_stack **b)
{
	int len_sa;

    len_sa = ft_stack_size(a);
    if (len_sa-- > 3 && !sorted(*a))
        pb(a, b);
    if (len_sa-- > 3 && !sorted(*a))
        pb(a, b);
    while (len_sa-- > 3 && !sorted(*a))
    {
        get_data_a(*a,*b);
        push_to_b(a,b);
    }
    sort_3(a);
    while (*b)
    {
        get_data_b(*a,*b);
        push_to_a(a,b);
    }
    current_index(*a);
    min_on_top(a);
}
