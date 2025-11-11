/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:45:00 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/11 15:34:46 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
/*
#include <stdio.h>
#include <stddef.h>

int	main(void)
{
	char	src[] = "aqui";
	char	dest[8] = "copiame"; 

	printf("%zu\n", ft_strlcpy(dest, src, 10)); 
	printf("%s\n", dest);                        
	return (0);
}
*/