/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 12:17:45 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/17 12:22:06 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_2(t_node **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_3(t_node **a)
{
	int	x;
	int	y;
	int	z;

	if (!a || !*a || !(*a)->next || !(*a)->next->next)
		return ;
	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;

	if (x > y && x > z)
		ra(a);
	else if (y > x && y > z)
		rra(a);
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

int	find_min(t_node *a)
{
	int		min;
	t_node	*tmp;

	if (!a)
		return (0);
	min = a->value;
	tmp = a->next;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	find_pos(t_node *a, int value)
{
	int	pos;

	pos = 0;
	while (a)
	{
		if (a->value == value)
			return (pos);
		pos++;
		a = a->next;
	}
	return (-1);
}

void	sort_5(t_node **a, t_node **b)
{
	int	size;
	int	min;
	int	pos;
	int	steps;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	while (size > 3)
	{
		min = find_min(*a);
		pos = find_pos(*a, min);
		if (pos <= size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			steps = size - pos;
			while (steps-- > 0)
				rra(a);
		}
		pb(a, b);
		size--;
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}

