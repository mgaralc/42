/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:35:24 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/12 16:49:08 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		{
				if (s[i] == (char)c)
						return ((char *)s + i);
				i++;
		}
		if ((char)c == '\0')
				return ((char *)s + i);
		return (NULL);

}
/*
int	main(void)
{
	const char	text[] = "hola niño";
	char		*ptr;

	ptr = ft_strchr(text, 'n');

	printf("%s\n", ptr);

}*/