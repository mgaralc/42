/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:35:24 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/18 17:22:08 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	leng;
	size_t	i;
	size_t	j;
	char	*result;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	leng = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(leng + 1);
	if (!result)
		return (NULL);
	while (s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = '\0';
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*result;

	s1 = "Uneme con ";
	s2 = "este texto";
	result = ft_strjoin(s1, s2);
	printf("%s\n", result);
}
*/
