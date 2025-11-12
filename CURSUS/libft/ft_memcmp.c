/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:31:13 by miguel            #+#    #+#             */
/*   Updated: 2025/11/12 18:55:04 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
  size_t i;

  i = 0;
  unsigned char *str1 = (unsigned char *)s1;
  unsigned char *str2 = (unsigned char *)s2;
  
  while (i < n && (str1[i] == str2[i]))
    i++;
  if (i == n)
    return (0);
  return (str1[i] - str2[i]);
}
int main(void)
{
	char s1[] = "buscame";
  char s2[] = "busczme";  
  
	printf("%d\n", ft_memcmp(s1, s2, 5));
}