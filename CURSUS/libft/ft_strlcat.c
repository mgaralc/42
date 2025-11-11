/* ******i******************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:35:24 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/11 17:55:37 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static	size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstleng;
	size_t	srcleng;
	size_t	i;

	i = 0;
	dstleng = ft_strlen(dst);
	srcleng = ft_strlen(src);

	if (size <= dlen)
		return size + slen;

	while (src[i] && dlen + i + 1 < size)
	{
		 dst[i + dstleng] = src[i];
		 i++;
	}
	dst[dlen + i] = '\0';
	return(dstleng + srcleng);
}

int	main(void)
{
	char	src[] = "origen";
	char	dest[] = "dest";

	ft_strlcat(dest, src, 5);

	printf("%s", dest);
}
