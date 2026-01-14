/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:45:46 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/19 10:40:30 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rr_aux(t_node **x)
{
	t_node	*prev;
	t_node	*curr;

	if (!x || !*x || !(*x)->next)
		return (0);
	prev = NULL;
	curr = *x;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *x;
	*x = curr;
	return (1);
}

void	rra(t_node **a)
{
	if (rr_aux(a))
		write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	if (rr_aux(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	int	cont;

	cont = 0;
	cont += rr_aux(a);
	cont += rr_aux(b);
	if (cont > 0)
		write(1, "rrr\n", 4);
}
