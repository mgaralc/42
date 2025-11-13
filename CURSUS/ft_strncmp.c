/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:51:18 by miguel            #+#    #+#             */
/*   Updated: 2025/11/12 18:10:00 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    size_t i;

    i = 0;
    while (i < n && s1[i] && s1[i] == s2[i])
        i++;
    if (i == n)
        return 0;
    return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
int main(void)
{
  char s1[] = "comparame";
  char s2[] = "compzrame";

  printf("%d\n", ft_strncmp(s1, s2, 7));
}*/