/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:34:06 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/17 13:17:05 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}


void	stack_add_back(t_node **head, t_node **tail, t_node *new_node)
{
	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		*tail = new_node;
	}
	else
	{
		(*tail)->next = new_node;
		*tail = new_node;
	}
}

int	stack_size(t_node *a)
{
	int	cont;

	cont = 0;
	while (a)
	{
		a = a->next;
		cont++;
	}
	return (cont);
}

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}



void	free_stack(t_node *a)
{
	t_node	*save;

	while (a)
	{
		save = a->next;
		free(a);
		a = save;
	}
}
