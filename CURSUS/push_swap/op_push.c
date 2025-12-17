/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:03:43 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/14 13:32:28 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_node **a, t_node **b)
{
	t_node	*aux;

	if (!b || !*b)
		return ;
	aux = *b;
	*b = aux->next;
	aux->next = *a;
	*a = aux;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*aux;

	if (!a || !*a)
		return ;
	aux = *a;
	*a = aux->next;
	aux->next = *b;
	*b = aux;
}
