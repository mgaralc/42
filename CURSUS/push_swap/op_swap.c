#include "push_swap.h"

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*a = second;
}

void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*b = second;
}

void  ss(t_node **a, t_node **b)
{
  sa(a);
  sb(b);
}