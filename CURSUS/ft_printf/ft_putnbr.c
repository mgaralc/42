/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:24:09 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/22 09:39:50 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int	num)
{
	long int	n;
	int	i;

	i = 0;
	n = num;
	if (n == 0)
		return (ft_putchar('0'));
	if (n < 0)
	{
		i += ft_putchar('-');
		n *= -1;
		
	}
	if (n > 9)
		i += ft_putnbr(n / 10);
	i += ft_putchar ((n % 10) + '0');
	return(i);
}
