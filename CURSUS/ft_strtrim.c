/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:35:24 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/11 18:30:00 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	leng;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	leng = ft_strlen(s1);
	if (leng == 0)
		return (ft_strdup(""));
	i = 0;
	j = leng - 1;
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while (j > i && is_in_set(s1[j], set))
		j--;
	if (i > j)
		return (ft_strdup(""));
	res = (char *)malloc((j - i + 2) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1 + i, j - i + 1);
	res[j - i + 1] = '\0';
	return (res);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "---HOLA---";
	char	set[] = "-";
	char	*result;

	result = ft_strtrim(s1, set);
	printf("Resultado: \"%s\"\n", result);
	free(result);
	return (0);
}
*/
