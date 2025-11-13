/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:08:01 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/10 16:40:30 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	int		i;
	char	str[] = "rellename";
	char	*aux;

	i = 0;
	aux = ft_memset(str, 'A', 4);
	while (aux[i])
	{
		write(1, &aux[i], 1);
		i++;
	}
}
*/