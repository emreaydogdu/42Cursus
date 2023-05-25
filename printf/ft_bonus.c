/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:04:23 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 15:51:45 by emaydogd         ###   ########.fr       */
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
			i = p->width - ((p->precision - n) + n);
		else
			i = p->width - n;
		p->precision -= i;
		while (i > 0 && i--)
			size += (int)write(1, " ", 1);
	}
	if (p->precision)
	{
		if (p->c == 's')
			i = 0;
		else if (p->dot && p->precision && p->width != 0)
			i = p->precision - (n);
		else
			i = p->precision - (n);
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
		p->zero = 1;
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
		p->sign = " ";
	while (**format == '+' && ++i && (*format)++)
		p->sign = "+";
	if (i)
		ft_check_b1(format, p);
}

void	ft_check_args(t_print *p)
{
	if (p->c == 'c' || p->c == 's' || p->c == 'p' || p->c == 'x' || p->c == 'X' || p->c == 'd' || p->c == 'i')
	{
		if (!p->minus && p->zero)
			p->pad = '0';
	}
}

void	ft_printArgs(t_print *p)
{
	printf("c[%c] -[%d] 0[%d] .[%d] p[%d] w[%2d] #[%d] \n", p->c, p->minus, p->zero, p->dot, p->precision, p->width, p->hash);
}

int	ft_psign(t_print *p)
{
	int	size;

	size = 0;
	size += (int)write(1, p->sign, ft_strlen(p->sign));
	p->sign = "";
	return (size);
}

int	ft_pwidth(int n, t_print *p)
{
	int	size;
	int	i;

	size = 0;
	i = n;
	if (p->c != 'd' && p->c != 'i')
		i = p->width - n - (p->sign != "");
	while (i > 0 && i--)
		size += (int)write(1, &p->pad, 1);
	return (size);
}

int	ft_pprecision(int n, t_print *p)
{
	int	size;
	int	i;

	size = 0;
	i = n;
	if (p->c != 'd' && p->c != 'i')
		i = p->precision - n;
	if (p->c == 's')
		i = 0;
	while (i > 0 && i--)
		size += (int)write(1, "0", 1);
	return (size);
}
