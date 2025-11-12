/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:10:31 by miguel            #+#    #+#             */
/*   Updated: 2025/11/12 18:30:37 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void *memchr(const void *s, int c, size_t n)
{
  size_t i;

  i = 0;
  unsigned char *str = (unsigned char *)s;
  
  while (i < n)
  {
    if (str[i] == (unsigned char) c)
    {
      return ((char *) &str[i]);
    }
    i++;
  }
  return (NULL);
}
/*
int main(void)
{
	char s[] = "buscame";
	printf("%s\n", (char *)memchr(s, 'u', 5));
}*/