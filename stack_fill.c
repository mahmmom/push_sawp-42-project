#include "push_swap.h"

void    start_stack(int count, char **args)
{
    int i;
    t_stack *s_a;

    if (!count || !args)
        error_handle();
    
    i = 1;
    s_a = create_stack(count);
    while (i <= count && !is_full(s_a))
    {
        push(s_a, ft_atoi(args[i]));
        i++;
    }

    printf("count = %d\n", s_a->count);
    printf("size = %d\n", s_a->size);
    
    printf("=======================\n");

    pop(s_a, s_a->stack);
    pop(s_a, s_a->stack);


    printf("count = %d\n", s_a->count);
    printf("size = %d\n", s_a->size);
   
   i = s_a->size - 1;
    while (i >= 0)
    {
        printf("item[%d] = %d\n", s_a->size - i, s_a->stack[i]);
        i--;
    }
}
