/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 13:51:18 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_print_i(char *nbstr, int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			count += ft_putchar('-');
	}
	else if (flags.plus == 1 && flags.zero == 0)
		count += ft_putchar('+');
	else if (flags.space == 1 && flags.zero == 0)
		count += ft_putchar(' ');
	if (flags.precision >= 0)
		count += ft_putwidth(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	count += ft_print_s(nbstr);
	return (count);
}

int	ft_print_sign_pre(int n, t_flags *flags)
{
	int	count;

	count = 0;
	if (n < 0 && flags->precision == -1)
	{
		count += ft_putchar('-');
		flags->width--;
	}
	else if (flags->plus == 1)
		count += ft_putchar('+');
	else if (flags->space == 1)
	{
		count += ft_putchar(' ');
		flags->width--;
	}
	return (count);
}

int	ft_putnumbr(char *nbstr, int n, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.zero)
		count += ft_print_sign_pre(n, &flags);
	if (flags.minus)
		count += ft_print_i(nbstr, n, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		if (n < 0 && flags.minus == 0)
			flags.width -= 1;
		count += ft_putwidth(flags.width, 0, 0);
	}
	else
		count += ft_putwidth(flags.width - flags.plus - flags.space,
				ft_strlen(nbstr), flags.zero);
	if (flags.minus == 0)
		count += ft_print_i(nbstr, n, flags);
	return (count);
}

int	ft_putnumbr_f(int n, t_flags flags)
{
	char	*nbstr;
	long	nb;
	int		count;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (flags.zero == 0)
			flags.width--;
	}
	if (flags.precision == 0 && n == 0)
		return (count + ft_putwidth(flags.width, 0, 0));
	nbstr = ft_itoa_h(nb);
	if (!nbstr)
		return (0);
	count += ft_putnumbr(nbstr, n, flags);
	free(nbstr);
	return (count);
}
