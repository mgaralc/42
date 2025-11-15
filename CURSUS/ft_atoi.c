/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:09:59 by miguel            #+#    #+#             */
/*   Updated: 2025/11/12 19:24:03 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_atoi(const char *nptr)
{
  int  sig;
  int num;
  int i;

  sig = 1;
  i = 0;
  num = 0;
  
  while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
  {
    i++;
  }

  if (nptr[i] == '-' || nptr[i] == '+')
  {
    if (nptr[i] == '-')
    {
      sig *= -1;
    }
    i++;    
  }

  while (nptr[i] >= '0' && nptr[i] <= '9')
  {
    num = (num * 10) + (nptr[i] - '0');
    i++;
  }
  
  return (num * sig);
}
/*
int main(void)
{
  char num[] = "-352";

  printf("%d", ft_atoi(num));
}*/