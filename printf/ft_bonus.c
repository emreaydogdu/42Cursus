/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:04:23 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/24 19:05:48 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_width(int n, t_print *p)
{
	int	size;
	int	i;

	size = 0;
	if (p->width)
	{
		if (p->dot && p->precision > n)
			i = p->width - ((p->precision - n) + n + p->sign);
		else
			i = p->width - n;
		while (i > 0 && i--)
			size += (int)write(1, " ", 1);
		if (p->width > p->precision)
			p->precision = 0;
	}
	if (p->precision)
	{
		if (p->dot && p->precision && p->width != 0 && p->c == 's')
			i = p->width - (n - p->sign);
		else if (p->dot && p->precision && p->width != 0)
			i = p->precision - (n - p->sign);
		size += ft_psign(p);
		while (i > 0 && i--)
			size += (int)write(1, &p->pad, 1);
	}
	p->precision = 0;
	p->width = 0;
	return (size);
}

void	ft_check_b1(char **format, t_print *p)
{
	int	i;

	i = 0;
	while (**format == '-' && ++i && (*format)++)
		p->minus = 1;
	while (**format == '0' && ++i && (*format)++)
		p->pad = '0';
	while (**format >= '0' && **format <= '9' && ++i && (*format))
		p->width = p->width * 10 + (*(*format)++ - '0');
	while (**format == '.' && ++i && (*format)++)
		p->dot = 1;
	while (p->dot && **format >= '0' && **format <= '9' && ++i && (*format))
		p->precision = p->precision * 10 + (*(*format)++ - '0');
	if (i)
		ft_check_b2(format, p);
}

void	ft_check_b2(char **format, t_print *p)
{
	int	i;

	i = 0;
	while (**format == '#' && ++i && (*format)++)
		p->hash = 1;
	while (**format == ' ' && ++i && (*format)++)
		p->space = 1;
	while (**format == '+' && ++i && (*format)++)
		p->plus = 1;
	if (i)
		ft_check_b1(format, p);
	else
	{
		if (p->plus)
			p->space = 0;
		if (p->dot)
			p->pad = '0';
		if (p->minus)
			p->pad = ' ';
	}
}

int	ft_pplus(t_print *p)
{
	p->plus = 0;
	return ((int)write(1, "+", 1));
}

int	ft_pspace(t_print *p)
{
	p->space = 0;
	return ((int)write(1, " ", 1));
}

int	ft_psign(t_print *p)
{
	if (p->sign)
	{
		p->sign = 0;
		return ((int)write(1, "-", 1));
	}
	else
		return (0);
}
