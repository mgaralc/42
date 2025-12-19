/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:01:37 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/18 16:40:45 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_index(t_node *a)
{
	int	max;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

int	max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = get_max_index(a);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	assign_index(t_node *a)
{
	t_node	*outer;
	t_node	*curr;
	int		rank;
	int		val;

	outer = a;
	while (outer)
	{
		rank = 0;
		val = outer->value;
		curr = a;
		while (curr)
		{
			if (curr->value < val)
				rank++;
			curr = curr->next;
		}
		outer->index = rank;
		outer = outer->next;
	}
}

void	radix_sort(t_node **a, t_node **b)
{
	int	size;
	int	bits;
	int	i;
	int	j;

	if (!a || !*a)
		return ;
	size = stack_size(*a);
	bits = max_bits(*a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a);
			else
				pb(a, b);
			j++;
		}
		while (*b)
			pa(a, b);
		i++;
	}
}
