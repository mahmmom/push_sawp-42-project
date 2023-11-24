#include "push_swap.h"

void	sort_2(t_stack **a)
{
	int	num1;
	int	num2;

	num1 = (*a)->content;
	num2 = (*a)->next->content;
	if (num1 > num2)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	num1;
	int	num2;
	int	num3;

	num1 = (*a)->content;
	num2 = (*a)->next->content;
	num3 = (*a)->next->next->content;
	if (num1 < num2 && num2 < num3 && num1 < num3)
		return ;
	else if (num1 < num2 && num2 > num3 && num1 < num3)
	{
		sa(a);
		ra(a);
	}
	else if (num1 > num2 && num2 < num3 && num1 < num3)
		sa(a);
	else if (num1 < num2 && num2 > num3 && num1 > num3)
		rra(a);
	else if (num1 > num2 && num2 < num3 && num1 > num3)
		ra(a);
	else if (num1 > num2 && num2 > num3 && num1 > num3)
	{
		sa(a);
		rra(a);
	}
}
bool	sorted(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next != NULL)
	{
		if (a->content > a->next->content)
			return (false);
		a = a->next;
	}
	return (true);
}
