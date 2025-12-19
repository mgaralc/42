/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:35:04 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/12/18 17:09:07 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_int_str(const char *s)
{
	int	i;

	if (!s || !s[0])
		return (0);
	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	parse_sign(const char *s, int *i)
{
	if (s[*i] == '-')
	{
		(*i)++;
		return (-1);
	}
	if (s[*i] == '+')
		(*i)++;
	return (1);
}

static int	accumulate(long *n, int sign, char c)
{
	*n = *n * 10 + (c - '0');
	if (sign == 1 && *n > 2147483647L)
		return (1);
	if (sign == -1 && -(*n) < -2147483648L)
		return (1);
	return (0);
}

int	atoi_safe(const char *s, int *out)
{
	long	n;
	int		sign;
	int		i;

	if (!is_valid_int_str(s))
		return (1);
	i = 0;
	sign = parse_sign(s, &i);
	n = 0;
	while (s[i])
	{
		if (accumulate(&n, sign, s[i]))
			return (1);
		i++;
	}
	*out = (int)(n * sign);
	return (0);
}

int	has_duplicate(t_node *a, int value)
{
	while (a)
	{
		if (a->value == value)
			return (1);
		a = a->next;
	}
	return (0);
}
