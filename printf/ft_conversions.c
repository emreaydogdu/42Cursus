/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:46:24 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 13:52:49 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_reset(t_print *p)
{
	p->spec = 0;
	p->width = 0;
	p->minus = 0;
	p->zero = 0;
	p->star = 0;
	p->precision = -1;
	p->hash = 0;
	p->space = 0;
	p->plus = 0;
}

void	ft_minus(t_print *p)
{
	p->minus = 1;
	p->zero = 0;
}

void	ft_width_num(char c, t_print *p)
{
	if (p->star == 1)
		p->width = 0;
	p->width = (p->width * 10) + (c - '0');
}

void	ft_width(va_list args, t_print *p)
{
	p->star = 1;
	p->width = va_arg(args, int);
	if (p->width < 0)
	{
		p->minus = 1;
		p->width *= -1;
	}
}

int	ft_precision(const char *str, int i, va_list args, t_print *p)
{
	if (str[++i] == '*')
		p->precision = va_arg(args, int);
	else
	{
		p->precision = 0;
		while (ft_isdigit(str[i]))
			p->precision = (p->precision * 10) + (str[i++] - '0');
	}
	return (i);
}
