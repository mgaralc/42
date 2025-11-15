/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:37:57 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/11 12:13:58 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


void *ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	unsigned char	*final;
	unsigned char   *orig;

	orig = (unsigned char *)src;
	final = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		final[i] = orig[i];
		i++;
	}

	return (dest);
}
/*
int main(void)
{
	char copiame[] = "Copiame";
	char dest[10];
	ft_memcpy(dest, copiame, 3);
	dest[3] = '\0';

	printf("%s", dest);    
}*/
