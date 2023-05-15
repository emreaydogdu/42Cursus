/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:55:21 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/14 23:56:42 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

int	ft_puthex(unsigned int n, int caps)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n >= 16)
		size += ft_puthex(n / 16, caps);
	if (caps == 'X')
		number = "0123456789ABCDEF"[n % 16];
	else
		number = "0123456789abcdef"[n % 16];
	return (size + (int)write(1, &number, 1));
}

int	ft_print_adress_hex(char *p)
{
	intptr_t	x;
	size_t		i;
	char		buf[9];

	x = (intptr_t)p;
	i = 0;
	while (i <= 8)
	{
		buf[i] = "0123456789abcdef"[(x >> ((8 - i) * 4)) & 0xf];
		i++;
	}
	write(1, "0x", 2);
	write(1, buf, sizeof(buf));
	return (sizeof(buf) + 2);
}

int	ft_formats(va_list args, const char c)
{
	int	size;

	size = 0;
	if (c == 'c')
		size = size + ft_putchar(va_arg(args, int));
	else if (c == 's')
		size = size + ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		size = size + ft_print_adress_hex(va_arg(args, void *));
	else if (c == 'i' || c == 'd')
		size = size + ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		size = size + ft_putunbr(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		size = size + ft_puthex(va_arg(args, int), c);
	else if (c == '%')
		size = size + (int)write(1, "%", 1);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	args;

	va_start(args, format);
	size = 0;
	while (*format)
	{
		if (*format == '%')
		{
			size += ft_formats(args, *(format + 1));
			format += 2;
		}
		else
			size += (int)write(1, format++, 1);
	}
	return (va_end(args), size);
}

/*
int	main(void)
{
	int i = 0, j = 0;
	//char *str  = "Pointer";
	//char *str2 = "Hello World";

	j = ft_printf("\n %c %c %c ", '0', 0, '1');
	i = printf("\n %c %c %c ", '0', 0, '1');

	printf("\n\nc: %d my: %d", i, j);
	return (0);
}
 */
