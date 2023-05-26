/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 22:38:35 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:30:24 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/17 15:27:40 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_x_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_print_s("0X");
	else
		ft_print_s("0x");
	return (2);
}

int	ft_print_x(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 0 && flags.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flags.precision >= 0)
		count += ft_putwidth(flags.precision - 1,
			ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

int	ft_puthex(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0)
		count += ft_print_x_prefix(is_upper);
	if (flags.minus == 1)
		count += ft_print_x(nbstr, n, is_upper, flags);
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
		count += ft_print_x(nbstr, n, is_upper, flags);
	return (count);
}

int	ft_puthex_f(unsigned int n, int is_upper, t_flags flags)
{
	char	*nbstr;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_putwidth(flags.width, 0, 0);
		return (count);
	}
	nbstr = ft_printf_xtoa(n, is_upper);
	if (!nbstr)
		return (0);
	count += ft_puthex(nbstr, n, is_upper, flags);
	free(nbstr);
	return (count);
}
