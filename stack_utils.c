#include "push_swap.h"

t_stack *ft_stack_new(int content)
{
	t_stack *ptr;

	ptr = (t_stack *)malloc(sizeof(*ptr));
	if(!ptr)
		return (NULL);
	ptr -> content = content;
	ptr -> next = NULL;
	return (ptr);
}

void ft_stack_add_back(t_stack **lst, t_stack *newnode)
{
	t_stack *current;

	if (!*lst)
	{
		*lst = newnode;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = newnode;
}

void	ft_stack_delone(t_stack *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	(del)(lst->content);
	free(lst);
}

void ft_stack_clear(t_stack **lst, void (*del)(int))
{
	t_stack	*ptr;
	t_stack	*temp;
	
	if (!lst ||!del)
		return ;
	ptr = *lst;
	while (ptr != NULL)
	{
		temp = ptr->next;
		ft_stack_delone(ptr, del);
		ptr = temp;
	}
	*lst = NULL;
}
int	ft_stack_size(t_stack **lst)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = (*lst);
	while (temp != NULL)
	{
		temp = temp -> next;
		count++;
	}
	return (count);
}