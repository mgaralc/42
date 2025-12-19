/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:15:48 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/17 13:18:24 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ss_aux(t_node **x)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (!x || !*x || !(*x)->next)
		return (0);
	first = *x;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*x = second;
	return (1);
}

void	sa(t_node **a)
{
	if (ss_aux(a))
		write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	if (ss_aux(b))
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	int	cont;

	cont = 0;
	cont += ss_aux(a);
	cont += ss_aux(b);
	if (cont > 0)
		write(1, "ss\n", 3);
}
