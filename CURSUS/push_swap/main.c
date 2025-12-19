/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:23:50 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/17 15:31:44 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (parse_args(argc, argv, &a))
	{
		write(2, "Error\n", 6);
		free_stack(a);
		return (1);
	}
	push_swap(&a, &b);
	free_stack(a);
	free_stack(b);
	return (0);
}
