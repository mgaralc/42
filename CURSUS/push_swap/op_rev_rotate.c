/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 18:45:46 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/14 19:57:18 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*curr;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	curr = *a;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *a;
	*a = curr;
}

void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*curr;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	curr = *b;
	while (curr->next)
	{
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	curr->next = *b;
	*b = curr;
}

void	rrr(t_node **a, t_node **b)
{
	rra(a);
	rrb(b);
}