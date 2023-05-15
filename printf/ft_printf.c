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
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c)
{
	return ((int) write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return ((int) write(1, s, i));
}

int	ft_putnbr(int n)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		size++;
	}
	if (n > 9)
		size += ft_putnbr(n / 10);
	number = (n % 10) + '0';
	return (size + (int) write(1, &number, 1));
}

int	ft_putunbr(unsigned int n)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n > 9)
		size += ft_putunbr(n / 10);
	number = (n % 10) + '0';
	return (size + (int)write(1, &number, 1));
}

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

int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_putchar(va_arg(args, int));
	else if (format == 's')
		print_length += ft_putstr(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_print_adress_hex(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_length += ft_putnbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_putunbr(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length += ft_puthex(va_arg(args, unsigned int), format);
	else if (format == '%')
		print_length += (int)write(1, "%", 1);
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

/*
int	ft_printf(const char *format, ...)
{
	int		size;
	va_list	ap;

	va_start(ap, format);
	size = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'c' && (format += 2))
			size = size + ft_putchar(va_arg(ap, int));
		else if (*format == '%' && *(format + 1) == 's' && (format += 2))
			size = size + ft_putstr(va_arg(ap, char *));
		else if (*format == '%' && *(format + 1) == 'p' && (format += 2))
			size = size + ft_print_adress_hex(va_arg(ap, void *));
		else if (*format == '%' && (*(format + 1) == 'i' || *(format + 1) == 'd') && (format += 2))
			size = size + ft_putnbr(va_arg(ap, int));
		else if (*format == '%' && *(format + 1) == 'u' && (format += 2))
			size = size + ft_putunbr(va_arg(ap, int));
		else if (*format == '%' && (*(format + 1) == 'x' || *(format + 1) == 'X') && (format += 2))
			size = size + ft_puthex(va_arg(ap, int), *(format - 1));
		else if (*format == '%' && *(format + 1) == '%' && (format += 2))
			size = size + (int)write(1, "%", 1);
		else
			size += (int)write(1, format++, 1);
	}
	return (va_end(ap), size);
}

 */

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