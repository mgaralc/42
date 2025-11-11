/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:35:24 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/11 16:55:26 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static	size_t	strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i):
}

size_t	strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstleng;
	size_t	srcleng;

	i = 0;
	dstleng = strlen();
	srcleng = strlen();
	while(i < (size - leng  - 1))
	{
		dest[dest +]
	}
}

int	main(void)
{
	char	src[] = "origen";
	char	dest[] = "dest";

	strlcat(src, dest, 5);
}
