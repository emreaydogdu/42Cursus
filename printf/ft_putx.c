/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 15:03:05 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_putx_f(int is_upper)
{
	if (is_upper == 1)
		ft_puts("0X");
	else
		ft_puts("0x");
	return (2);
}

static int	ft_putx(char *nbstr, int n, int is_upper, t_print flags)
{
	int	count;

	count = 0;
	if (flags.zero == 0 && flags.hash == 1 && n != 0)
		count += ft_putx_f(is_upper);
	if (flags.precision >= 0)
		count += ft_putwidth(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_puts(nbstr);
	return (count);
}

static int	ft_puthex(char *nbstr, int n, int is_upper, t_print flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0)
		count += ft_putx_f(is_upper);
	if (flags.minus == 1)
		count += ft_putx(nbstr, n, is_upper, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_putwidth(flags.width, 0, 0);
	}
	else
		count += ft_putwidth(flags.width,
				ft_strlen(nbstr) + (flags.hash * 2), flags.zero);
	if (flags.minus == 0)
		count += ft_putx(nbstr, n, is_upper, flags);
	return (count);
}

int	ft_puthex_f(unsigned int n, int is_upper, t_print p)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (p.precision == 0 && n == 0)
	{
		count += ft_putwidth(p.width, 0, 0);
		return (count);
	}
	nbstr = ft_xtoa_h(n, is_upper);
	if (!nbstr)
		return (0);
	count += ft_puthex(nbstr, n, is_upper, p);
	free(nbstr);
	return (count);
}
