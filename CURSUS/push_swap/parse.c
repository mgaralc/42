/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:32:04 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/19 10:49:21 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split(char **s)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}

static int	free_and_fail(char **tokens, int do_free)
{
	if (do_free)
		free_split(tokens);
	return (1);
}

static int	get_tokens(int argc, char **argv, char ***tokens)
{
	if (argc == 2)
	{
		*tokens = ft_split(argv[1], ' ');
		if (!*tokens || !(*tokens)[0])
		{
			free_split(*tokens);
			return (1);
		}
	}
	else
		*tokens = argv + 1;
	return (0);
}

static int	build_stack(t_node **a, char **tokens, int do_free)
{
	int		i;
	int		value;
	t_node	*tail;
	t_node	*new;

	i = 0;
	tail = NULL;
	while (tokens[i])
	{
		if (atoi_safe(tokens[i], &value) || has_duplicate(*a, value))
			return (free_and_fail(tokens, do_free));
		new = node_new(value);
		if (!new)
			return (free_and_fail(tokens, do_free));
		stack_add_back(a, &tail, new);
		i++;
	}
	if (do_free)
		free_split(tokens);
	return (0);
}

int	parse_args(int argc, char **argv, t_node **a)
{
	char	**tokens;

	if (get_tokens(argc, argv, &tokens))
		return (1);
	return (build_stack(a, tokens, argc == 2));
}
