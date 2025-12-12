/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:02:03 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/12 20:10:31 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

t_node	*node_new(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	return (node);
}

static void	stack_add_back(t_node **head, t_node **tail, t_node *new)
{
	if (!new)
		return ;
	if (!*head)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
}

int	stack_size(t_node *a)
{
	int	cont;

	cont = 0;

	while (a)
	{
		a = a ->next;
		cont++;
	}
	return (cont);
}

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > (a->next->value))
		{
			return (0);
		}
		a = a->next;
	}
	return (1);
}

void	print_stack(t_node *a, char name)
{
	ft_putchar_fd(name, 1);
	ft_putstr_fd(": ", 1);
	while (a)
	{
		ft_putnbr_fd(a->value, 1);
		ft_putchar_fd(' ', 1);
		a = a->next;
	}
	ft_putchar_fd('\n', 1);
}


void	push_swap(t_node **a, t_node **b)
{
	int	size;

	print_stack(*a, 'A');
	print_stack(*b, 'B');
	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	(void)b;
	(void)size; 
}


int	main(void)
{
	int		i;
	int		values[] = {4, 2, 3, 1};
	int		size;
	t_node	*a;
	t_node	*b;
	t_node	*tail;
	t_node	*new;

	i = 0;
	size = 4;
	a = NULL;
	b = NULL;
	tail = NULL;
	while (i < size)
	{
		new = node_new(values[i]);
		if (!new)
			return (1);
		stack_add_back(&a, &tail, new);
		i++;
	}
	push_swap(&a, &b);
	return (0);
}
