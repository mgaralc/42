/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:36:48 by miguel            #+#    #+#             */
/*   Updated: 2025/11/15 12:05:04 by miguel           ###   ########.fr       */
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
	while (i > 0)
	{
		i--;
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	i;
	size_t	start;
	size_t	end;

	if (!s)
		return (NULL);
	words = ft_wordcount(s, c);
	tab = (char **)malloc((words + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	i = 0;
	start = 0;
	while (i < words)
	{
		while (s[start] && s[start] == c)
			start++;
		end = start;
		while (s[end] && s[end] != c)
			end++;
		tab[i] = ft_substr(s, start, end - start);
		if (!tab[i])
			return (ft_free_split(tab, i));
		i++;
		start = end;
	}
	tab[i] = NULL;
	return (tab);
}

/*
#include <stdio.h>
#include "libft.h"

int main(void)
{
	char	**result;
	size_t	i;

	result = ft_split("hola que tal", ' ');
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