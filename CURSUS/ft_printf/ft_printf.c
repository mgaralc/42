/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:52:20 by miguel            #+#    #+#             */
/*   Updated: 2025/11/20 21:23:34 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdint.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	
	if (!s)
		return (ft_putstr("(null)"));

	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

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
	else if (format == 'p')
	{
		return (ft_print_ptr(va_arg(vargs, void *)));
	}
	else if (format == 'd')
	{
		return (ft_putnbr(va_arg(vargs, int)));
	}
	else if (format == 'x')
	{
		return (ft_print_hex(va_arg(vargs, unsigned int), "0123456789abcdef"));
	}
	else if (format == 'X')
	{
		return (ft_print_hex(va_arg(vargs, unsigned int), "0123456789ABCDEF"));
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
		else
		{
			if (f[ i + 1] == '\0')
			{
				cont += ft_putchar('%');
				va_end(vargs);
				return (cont);
			}
			else
			{
				cont += converter(f[i+1], vargs);
				i++;
			}
		}
		i++;
	}
	va_end(vargs);
	return (cont);
}

int	main(void)
{
	int	x = 42;
	ft_printf("Escribe esto %d\n", x);
	return (0);
}
