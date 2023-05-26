/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:57:31 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/26 13:15:18 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset(t_flags *p)
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

void	ft_minus(t_flags *p)
{
	p->minus = 1;
	p->zero = 0;
}

void	ft_width_num(char c, t_flags *p)
{
	if (p->star == 1)
		p->width = 0;
	p->width = (p->width * 10) + (c - '0');
}

void	ft_width(va_list args, t_flags *p)
{
	p->star = 1;
	p->width = va_arg(args, int);
	if (p->width < 0)
	{
		p->minus = 1;
		p->width *= -1;
	}
}

int	ft_precision(const char *str, int i, va_list args, t_flags *p)
{
	i++;
	if (str[i] == '*')
	{
		p->precision = va_arg(args, int);
		return (++i);
	}
	p->precision = 0;
	while (ft_isdigit(str[i]))
	{
		p->precision = (p->precision * 10) + (str[i] - '0');
		i++;
	}
	return (i);
}
