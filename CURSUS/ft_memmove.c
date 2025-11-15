/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:37:57 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/11 15:10:32 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void    *ft_memmove(void *dst, const void *src, size_t len)
{
    char    *c_src;
    char    *c_dst;
    size_t    i;
    
    if (!dst && !src)
        return (NULL);
    c_src = (char *) src;
    c_dst = (char *) dst;
    i = 0;
    if (c_dst > c_src)
        while (len-- > 0)
            c_dst[len] = c_src[len];

    else
    {
        while (i++ < len)
            c_dst[i] = c_src[i];
    }
    return (dst);
}
/*
int	main(void)
{
	char	str[20] = "ABCDEFGHIJ";

	ft_memmove(str + 3, str, 5);
	printf("%s\n", str);

	return (0);
}
*/