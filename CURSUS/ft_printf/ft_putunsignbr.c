/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsignbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:24:28 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/24 11:32:39 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsignbr(unsigned int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 9)
		i += ft_putunsignbr(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
