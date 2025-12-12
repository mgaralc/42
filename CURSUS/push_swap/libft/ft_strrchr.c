/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:35:31 by miguel            #+#    #+#             */
/*   Updated: 2025/11/18 16:53:19 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pos;

	i = 0;
	pos = -1;
	while (s[i])
	{
		if (s[i] == (char)c)
			pos = i;
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	if (pos == -1)
		return (NULL);
	else
		return ((char *)&s[pos]);
}
/*
int	main(void)
{
	const char	text[] = "la n ultima es n esta";
	char		*ptr;

	ptr = ft_strrchr(text, 'n');

	printf("%s\n", ptr);
}*/