#include "push_swap.h"

void    current_index(t_stack   **a)
{
    int i;
    int median;

    i = 0;
    if (!a)
        return;
    median = ft_stack_size(a) / 2;
    while (*a)
    {
        (*a)->index = i;
        if (i <= median)
            (*a)->above_average = true;
        else
            (*a)->above_average = false;
        (*a) = (*a)->next;
        ++i;
    }
}

static void set_target_a(t_stack  **a, t_stack **b)
{
    t_stack *current_b;
    t_stack *target_node;
    long    best_mtach_index;

    while (*a)
    {
        best_mtach_index = LONG_MIN;
        current_b = (*b);
        while (current_b)
        {
            if (current_b->content < (*a)->content
                && current_b->content > best_mtach_index)
            {
                best_mtach_index = current_b->content;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_mtach_index == LONG_MIN)
            (*a)->targeted_node = find_max(b);
        else
            (*a)->targeted_node = target_node;
        (*a) = (*a)->next;
    }
}

static void cost_analysis(t_stack **a, t_stack **b)
{
    int len_sa;
    int len_sb;

    len_sa = ft_stack_size(a);
    len_sb = ft_stack_size(b);
    while (*a)
    {
        (*a)->push_count = (*a)->index;
        if (!((*a)->above_average))
            (*a)->push_count = len_sa - ((*a)->index);
        if (!((*a)->above_average))
            (*a)->push_count = len_sa - ((*a)->index);
        else
            (*a)->push_count += len_sb - ((*a)->targeted_node->index);
        (*a) = (*a)->next;
    }
}
