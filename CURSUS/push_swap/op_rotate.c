/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:34:03 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/17 13:07:35 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rrr_aux(t_node **x)
{
	t_node	*first;
	t_node	*last;

	if (!x || !*x || !(*x)->next)
		return (0);
	first = *x;
	*x = first->next;
	last = *x;
	while (last->next)
		last = last->next;
	last->next = first;
	first->next = NULL;
	return (1);
}

void	ra(t_node **a)
{
	if (rrr_aux(a))
		write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	if (rrr_aux(b))
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	int	cont;

	cont = 0;
	cont += rrr_aux(a);
	cont += rrr_aux(b);
	if (cont > 0)
		write(1, "rr\n", 3);
}
