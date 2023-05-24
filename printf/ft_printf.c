/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:55:21 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/24 18:46:14 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_reset(t_print *p)
{
	p->c = '\0';
	p->hash = 0;
	p->sign = 0;
	p->plus = 0;
	p->space = 0;
	p->pad = ' ';
	p->minus = 0;
	p->width = 0;
	p->dot = 0;
	p->precision = 0;
}

char	*ft_formats(va_list args, char *format, t_print *p)
{
	ft_check_b1(&format, p);
	ft_check_b2(&format, p);
	if (*format == 'c')
		p->len += ft_putchar(va_arg(args, int), p);
	else if (*format == 's')
	{
		p->c = 's';
		p->pad = ' ';
		p->len += ft_putstr(va_arg(args, char *), p);
	}
	else if (*format == 'p')
		p->len += ft_putptr(va_arg(args, unsigned long), p);
	else if (*format == 'i' || *format == 'd')
		p->len += ft_putnbr(va_arg(args, int), p);
	else if (*format == 'u')
		p->len += ft_putunbr(va_arg(args, int), p);
	else if (*format == 'x' || *format == 'X')
		p->len += ft_puthex(va_arg(args, int), *format, p);
	else if (*format == '%')
		p->len += ft_putchar('%', p);
	return (++format);
}

int	ft_printf(const char *format, ...)
{
	char	*f;
	t_print	p;
	va_list	args;

	va_start(args, format);
	p.len = 0;
	f = (char *)format;
	while (*f)
	{
		ft_reset(&p);
		if (*f == '%')
			f = ft_formats(args, ++f, &p);
		else
			p.len += (int)write(1, f++, 1);
	}
	return (va_end(args), p.len);
}
/*
int	main(void)
{
	int	i;
	int	j;
	char	*s = "1234";

	ft_printf("|");
	j = ft_printf("%-5.7s", "us");
	printf("|\n|");
	i = printf("%-5.7s", "us");
	printf("|");
	printf("\n\nc: %d my: %d", i, j);
	return (0);
}
*/