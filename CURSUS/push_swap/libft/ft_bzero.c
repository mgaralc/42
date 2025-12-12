/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:34:58 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/18 17:20:49 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
}
/*
int	main(void)
{
	char	str[] = "rellename";
	int		i;

	ft_bzero(str, 3);
	i = 0;

	while (i < (int) sizeof(str) - 1)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}*/