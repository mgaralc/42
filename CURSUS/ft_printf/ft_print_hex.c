/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:23:23 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/24 10:42:43 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(uintptr_t n, char *base)
{
	int		i;
	int		cont;
	int		rest;
	char	digs[16];

	i = 0;
	cont = 0;
	if (n == 0)
	{
		ft_putchar('0');
		return (1);
	}
	while (n > 0)
	{
		rest = n % 16;
		digs[i] = base[rest];
		n /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		cont += ft_putchar(digs[i]);
	}
	return (cont);
}
