/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel <miguel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:38:11 by miguel            #+#    #+#             */
/*   Updated: 2025/11/16 11:42:55 by miguel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
  long  int num = n;
  
  if (num < 0)
  {
    write(fd, "-", 1);
    num *= -1;
  }

  if (num > 9)
  {
    ft_putnbr_fd(num / 10, fd);
  }
  ft_putchar_fd((num % 10) + '0', fd);
}