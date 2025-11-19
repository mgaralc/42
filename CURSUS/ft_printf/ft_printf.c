/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:52:20 by miguel            #+#    #+#             */
/*   Updated: 2025/11/19 21:41:22 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

/* CAMBIO: tipo de retorno pasa de char a int */
int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

static int	converter(char format, va_list vargs)
{
	if (format == 'c')
	{
		return (ft_putchar((char)va_arg(vargs, int)));
	}
	else if (format == 's')
	{
		return (ft_putstr(va_arg(vargs, char *)));
	}
	else if (format == '%')
	{
		return (ft_putchar('%'));
	}
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
		if (f[i] != '%')
		{
			cont += ft_putchar(f[i]);
		}
		else if (f[i] == '%')
		{
			cont += converter(f[i + 1], vargs);
			i++;
		}
		i++;
	}
	va_end(vargs);
	return (cont);
}

int	main(void)
{
	ft_printf("Escribe %c esto %s\n", 'D', "porfa");
	return (0);
}
