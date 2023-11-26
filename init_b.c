#include "push_swap.h"

static void set_target_b(t_stack  *a, t_stack *b)
{
    t_stack *current_a;
    t_stack *target_node;
    long    best_mtach_index;

    while (b)
    {
        best_mtach_index = LONG_MAX;
        current_a = a;
        while (current_a)
        {
            if (current_a->content > b->content
                && current_a->content < best_mtach_index)
            {
                best_mtach_index = current_a->content;
                target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_mtach_index == LONG_MAX)
            b->targeted_node = find_min(a);
        else
            b->targeted_node = target_node;
        b = b->next;
    }
}

void	init_stack_b(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_b(a, b);
}