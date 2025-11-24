/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarcia2 <mgarcia2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 09:38:16 by mgarcia2          #+#    #+#             */
/*   Updated: 2025/11/24 11:31:20 by mgarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *f, ...);
int	ft_putchar(char c);
int	ft_putunsignbr(unsigned int n);
int	ft_putnbr(int num);
int	ft_print_ptr(void *ptr);
int	ft_print_hex(uintptr_t n, char *base);
int	ft_putstr(char *s);

#endif