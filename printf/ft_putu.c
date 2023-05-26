/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 22:40:19 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunumbr_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:15:24 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/17 15:42:11 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(char *nbstr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_putwidth(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

int	ft_putunumbr(char *nbstr, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_print_u(nbstr, flags);
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
		count += ft_print_u(nbstr, flags);
	return (count);
}

int	ft_putunumbr_f(unsigned n, t_flags flags)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_putwidth(flags.width, 0, 0);
		return (count);
	}
	nbstr = ft_printf_utoa(n);
	if (!nbstr)
		return (0);
	count += ft_putunumbr(nbstr, flags);
	free(nbstr);
	return (count);
}
