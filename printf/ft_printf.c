/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:55:21 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/20 15:50:23 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "ft_printf.h"

char	*ft_check(char *format, t_print *p)
{
	format++;
	if (*format == '#')
	{
		p->hash = 1;
		while (*format == '#')
			format++;
		format = ft_check(--format, p);
	}
	if (*format == ' ')
	{
		p->space = 1;
		while (*format == ' ')
			format++;
		format = ft_check(--format, p);
	}
	if (*format == '+')
	{
		p->plus = 1;
		while (*format == '+')
			format++;
		format = ft_check(--format, p);
	}
	/*
	if (*format >= '1' && *format <= '9')
	{
		while (*format >= '0' && *format <= '9')
			p->width = p->width * 10 + (*format++ - '0');
		format = ft_check(--format, p);
	}
	*/
	return (format);
}

void	ft_reset(t_print *p)
{
	p->c = '\0';
	p->hash = 0;
	p->plus = 0;
	p->space = 0;
	//p->width = 0;
	//p->minus = 0;
}

char	*ft_formats(va_list args, char *format, t_print *p)
{
	format = ft_check(format, p);
	if (*format == 'c')
		p->len += ft_putchar(va_arg(args, int));
	else if (*format == 's')
		p->len += ft_putstr(va_arg(args, char *));
	else if (*format == 'p')
		p->len += ft_puthexph(va_arg(args, unsigned long));
	else if (*format == 'i' || *format == 'd')
		p->len += ft_putnbr_b(va_arg(args, int), p);
	else if (*format == 'u')
		p->len += ft_putunbr(va_arg(args, int));
	else if (*format == 'x' || *format == 'X')
		p->len += ft_puthex(va_arg(args, int), p->c, p);
	else if (*format == '%')
		p->len += (int)write(1, "%", 1);
	return (++format);
}

int	ft_printf(const char *format, ...)
{
	t_print	p;
	va_list	args;

	va_start(args, format);
	p.len = 0;
	while (*format)
	{
		ft_reset(&p);
		if (*format == '%')
			format = ft_formats(args, format, &p);
		else
			p.len += (int)write(1, format++, 1);
	}
	return (va_end(args), p.len);
}

int	main(void)
{
	int	i;
	int	j;

	j = ft_printf("|%# +d|\n", 3100);
	i = printf("|%+d|\n", 3100);
	printf("\n\nc: %d my: %d", i, j);
	return (0);
}
