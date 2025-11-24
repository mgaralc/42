/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:52:20 by miguel            #+#    #+#             */
/*   Updated: 2025/11/24 11:50:56 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	converter(char format, va_list vargs)
{
	if (format == 'c')
		return (ft_putchar((char)va_arg(vargs, int)));
	else if (format == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (format == 'p')
		return (ft_print_ptr(va_arg(vargs, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (format == 'u')
		return (ft_putunsignbr(va_arg(vargs, unsigned int)));
	else if (format == 'x')
		return (ft_print_hex(va_arg(vargs, unsigned int), "0123456789abcdef"));
	else if (format == 'X')
		return (ft_print_hex(va_arg(vargs, unsigned int), "0123456789ABCDEF"));
	else if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *f, ...)
{
	va_list	vargs;
	int		cont;
	int		i;

	va_start(vargs, f);
	cont = 0;
	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
		{
			if (f[i + 1] == '\0')
			{
				cont += ft_putchar('%');
				break ;
			}
			cont += converter(f[i + 1], vargs);
			i++;
		}
		else
			cont += ft_putchar(f[i]);
		i++;
	}
	va_end(vargs);
	return (cont);
}
/*
int	main(void)
{
	char			*str;
	char			c;
	int 	x;
	void	 *ptr;

	c = 'a';
	str = "Escribeme en la terminal";
	x = 123;
	ptr = &x;
	ft_printf("El caracter es %c\n", c);
	printf("El caracter es %c\n", c);
	ft_printf("String: %s\n", str);
	printf("String: %s\n", str);
	ft_printf("Puntero: %p\n", ptr);
	printf("Puntero: %p\n", ptr);
	ft_printf("Int max: %d, Int min: %i\n", 0, -521);
	printf("Int max: %d, Int max: %i\n", 0, -521);
	ft_printf("Unsigned int: %u\n", 429496729);
	printf("Unsigned int: %u\n", 429496729);
	ft_printf("Hexadecimal en minuscula: %x\n", 255);
	printf("Hexadecimal en minuscula:: %x\n", 255);
	ft_printf("Hexadecimal en minuscula: %X\n", 255);
	printf("Hexadecimal en minuscula:: %X\n", 255);
}
*/