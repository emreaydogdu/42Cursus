/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 14:55:36 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putu(char *nbstr, t_print flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_putwidth(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_puts(nbstr);
	return (count);
}

static int	ft_putunumbr(char *nbstr, t_print flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putu(nbstr, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_putwidth(flags.width, 0, 0);
	}
	else
		count += ft_putwidth(flags.width, ft_strlen(nbstr), flags.zero);
	if (flags.minus == 0)
		count += ft_putu(nbstr, flags);
	return (count);
}

int	ft_putunumbr_f(unsigned n, t_print p)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (p.precision == 0 && n == 0)
	{
		count += ft_putwidth(p.width, 0, 0);
		return (count);
	}
	nbstr = ft_utoa_h(n);
	if (!nbstr)
		return (0);
	count += ft_putunumbr(nbstr, p);
	free(nbstr);
	return (count);
}
