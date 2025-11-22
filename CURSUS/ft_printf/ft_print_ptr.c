/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:23:52 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/22 09:39:54 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_ptr(void *ptr)
{
	int			cont;
	uintptr_t	num;

	num = (uintptr_t)ptr;
	cont = 0;
	cont += ft_putstr("0x");
	cont += ft_print_hex(num, "0123456789abcdef");
	return (cont);
}