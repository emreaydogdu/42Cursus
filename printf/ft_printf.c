/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:55:21 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/22 11:49:34 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>
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
	return (format);
}

void	ft_reset(t_print *p)
{
	p->c = '\0';
	p->hash = 0;
	p->plus = 0;
	p->space = 0;
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
		p->len += ft_puthex(va_arg(args, int), *format, p);
	else if (*format == '%')
		p->len += (int)write(1, "%", 1);
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
			f = ft_formats(args, f, &p);
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

	j = ft_printf("|% 1s|\n", "");
	i = printf("|% 1s|\n", "");
	printf("\n\nc: %d my: %d", i, j);
	return (0);
}
*/