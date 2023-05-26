/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:46:24 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 13:52:30 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_putarg(char type, va_list args, t_print *p)
{
	if (type == 'c')
		p->size += ft_putchar_f(va_arg(args, int), *p);
	else if (type == 's')
		p->size += ft_putstr_f(va_arg(args, const char *), *p);
	else if (type == 'd' || type == 'i')
		p->size += ft_putnumbr_f(va_arg(args, int), *p);
	else if (type == 'x' || type == 'X')
		p->size += ft_puthex_f(va_arg(args, unsigned int),
				type == 'X', *p);
	else if (type == 'u')
		p->size += ft_putunumbr_f(va_arg(args, unsigned int), *p);
	else if (type == 'p')
		p->size += ft_putptr_f((unsigned long int) va_arg(args, void *), *p);
	else if (type == '%')
		p->size += ft_putchar_f('%', *p);
}

int	ft_parse_args(const char *str, int i, va_list args, t_print *p)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			ft_minus(p);
		if (str[i] == '#')
			p->hash = 1;
		if (str[i] == ' ')
			p->space = 1;
		if (str[i] == '+')
			p->plus = 1;
		if (str[i] == '0' && p->minus == 0 && p->width == 0)
			p->zero = 1;
		if (str[i] == '.')
			i = ft_precision(str, i, args, p);
		if (str[i] == '*')
			ft_width(args, p);
		if (ft_isdigit(str[i]))
			ft_width_num(str[i], p);
		if (ft_istype(str[i]))
		{
			p->spec = (int)str[i];
			break ;
		}
	}
	return (i);
}

void	ft_parse(char *str, va_list args, t_print *p)
{
	int	i;
	int	x;

	i = -1;
	while (str[++i])
	{
		ft_reset(p);
		if (str[i] == '%' && str[i + 1])
		{
			x = ft_parse_args(str, i, args, p);
			if (p->spec)
				i = x;
			if (str[i] && p->spec && ft_istype(str[i]))
				ft_putarg(str[i], args, p);
			else if (str[i])
				p->size += ft_putchar(str[i]);
		}
		else
			p->size += ft_putchar(str[i]);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	t_print	p;
	char	*str;

	p.size = 0;
	if (!format || *format == '\0')
		return (0);
	str = (char *)format;
	va_start(args, format);
	ft_parse(str, args, &p);
	va_end(args);
	return (p.size);
}
