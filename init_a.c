#include "push_swap.h"

void    current_index(t_stack   *stack)
{
    int i;
    int median;

    i = 0;
    if (!stack)
        return;
    median = ft_stack_size(stack) / 2;
    while (stack)
    {
        stack->index = i;
        if (i <= median)
            stack->above_average = true;
        else
            stack->above_average = false;
        stack = stack->next;
        ++i;
    }
}

static void set_target_a(t_stack  *a, t_stack *b)
{
    t_stack *current_b;
    t_stack *target_node;
    long    best_mtach_index;

    while (a)
    {
        best_mtach_index = LONG_MIN;
        current_b = b;
        while (current_b)
        {
            if (current_b->content < a->content
                && current_b->content > best_mtach_index)
            {
                best_mtach_index = current_b->content;
                target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_mtach_index == LONG_MIN)
            a->targeted_node = find_max(b);
        else
            a->targeted_node = target_node;
        a = a->next;
    }
}

static void cost_analysis(t_stack *a, t_stack *b)
{
    int len_sa;
    int len_sb;

    len_sa = ft_stack_size(a);
    len_sb = ft_stack_size(b);
    while (a)
    {
        a->push_count = a->index;
        if (!(a->above_average))
            a->push_count = len_sa - (a->index);
        if (a->above_average)
            a->push_count += (a->targeted_node->index);
        else
            a->push_count += len_sb - (a->targeted_node->index);
        a = a->next;
    }
}
void	set_cheapest(t_stack *stack)
{
	long	cheapest_val;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_val = LONG_MAX;
	while (stack)
	{
		if (stack->push_count < cheapest_val)
		{
			cheapest_val = stack->push_count;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->lowest_moves = true;
}

void	init_stack_a(t_stack *a, t_stack *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}