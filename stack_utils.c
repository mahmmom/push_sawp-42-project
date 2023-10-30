#include "push_swap.h"

t_stack   *create_stack(int   count)
{
     if (count <= 0)
        return (NULL);

    t_stack   *stack = malloc(sizeof(stack));
    if (!stack)
        return (NULL);

    stack->stack = malloc(sizeof(int) * count);
    if (!stack->stack)
    {
        return (NULL);
        free(stack);
    }
    stack->count = count;
    stack->size = 0;

    return (stack);
}

void    destroy_stack(t_stack *stack)
{
    free(stack->stack);
    free(stack);
}

bool    is_full(t_stack   *stack)
{
    return (stack->count == stack->size);
}

bool    is_empty(t_stack  *stack)
{
    return (stack->size == 0);
}

bool    push(t_stack *stack,  int item)
{
    if (is_full(stack))
        return (false);
    
    stack->stack[stack->size] = item;
    stack->size++;

    return (true);
}

bool pop(t_stack *stack, int *item)
{
    if (is_empty(stack))
        return false;

    *item = stack->stack[stack->size - 1];
    stack->size--;
    return true;
}

bool    peekt(t_stack  *stack, int *item)
{
    if (is_empty(stack))
        return (false);

   *item =  stack->stack[stack->size--];

    return (true);
}
