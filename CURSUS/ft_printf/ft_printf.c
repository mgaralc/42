/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 17:52:20 by miguel            #+#    #+#             */
/*   Updated: 2025/11/22 09:55:35 by mgarcia2         ###   ########.fr       */
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
		if (f[i] != '%')
		{
			cont += ft_putchar(f[i]);
		}
		else
		{
			if (f[i + 1] == '\0')
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
	int             ret_ft;
	int             ret_ori;
	char            c = 'A';
	char            *s = "Hola 42";
	char            *null_str = NULL;
	int             d = -4242;
	int             i = 123456;
	unsigned int    u = 3000000000u;
	unsigned int    hex = 0xdeadbeef;
	void            *ptr = s;

	ret_ft = ft_printf("TEST %%c -> [%c]\n", c);
	ret_ori = printf ("TEST %%c -> [%c]\n", c);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%s -> [%s]\n", s);
	ret_ori = printf ("TEST %%s -> [%s]\n", s);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%s (NULL) -> [%s]\n", null_str);
	ret_ori = printf ("TEST %%s (NULL) -> [%s]\n", null_str);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%p -> [%p]\n", ptr);
	ret_ori = printf ("TEST %%p -> [%p]\n", ptr);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%d -> [%d]\n", d);
	ret_ori = printf ("TEST %%d -> [%d]\n", d);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%i -> [%i]\n", i);
	ret_ori = printf ("TEST %%i -> [%i]\n", i);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%u -> [%u]\n", u);
	ret_ori = printf ("TEST %%u -> [%u]\n", u);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%x -> [%x]\n", hex);
	ret_ori = printf ("TEST %%x -> [%x]\n", hex);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%X -> [%X]\n", hex);
	ret_ori = printf ("TEST %%X -> [%X]\n", hex);
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	ret_ft = ft_printf("TEST %%%% -> [%%]\n");
	ret_ori = printf ("TEST %%%% -> [%%]\n");
	printf("return ft: %d | return ori: %d\n\n", ret_ft, ret_ori);

	return (0);
}