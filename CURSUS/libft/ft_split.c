/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:36:48 by miguel            #+#    #+#             */
/*   Updated: 2025/11/18 17:21:53 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		in_word;

	count = 0;
	i = 0;
	in_word = 0;
	while (s[i])
	{
		if (s[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static char	**ft_free_split(char **tab, size_t i)
{
	if (!tab)
		return (NULL);
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

static int	ft_fill_word(char const *s, const char **p, char c, char **res)
{
	const char		*start;
	const char		*end;
	unsigned int	off;
	size_t			len;

	start = *p;
	while (*start && *start == c)
		start++;
	end = start;
	while (*end && *end != c)
		end++;
	off = (unsigned int)(start - s);
	len = (size_t)(end - start);
	*res = ft_substr(s, off, len);
	*p = end;
	return (*res != NULL);
}

char	**ft_split(char const *s, char c)
{
	char const	*p;
	char		**tab;
	size_t		words;
	size_t		i;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	tab = malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	p = s;
	while (i < words)
	{
		if (!ft_fill_word(s, &p, c, &tab[i]))
			return (ft_free_split(tab, i));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char **result;
	size_t i;

	result = ft_split("hola que tal", ' ');
	if (!result)
		return (1);
	i = 0;
	printf("Caso 1:\n");
	while (result[i])
	{
		printf(" - \"%s\"\n", result[i]);
		free(result[i]);
		i++;
	}
	free(result);
	return (0);
}*/