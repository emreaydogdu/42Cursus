/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 15:02:19 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puts(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}

static	int	ft_putpres(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

static int	ft_putstr(const char *str, t_print flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_putwidth(flags.precision, ft_strlen(str), 0);
		count += ft_putpres(str, flags.precision);
	}
	else
		count += ft_putpres(str, ft_strlen(str));
	return (count);
}

int	ft_putstr_f(const char *str, t_print p)
{
	int	count;

	count = 0;
	if (str == NULL && p.precision >= 0 && p.precision < 6)
		return (count + ft_putwidth(p.width, 0, 0));
	if (str == NULL)
		str = "(null)";
	if (p.precision >= 0 && (size_t)p.precision > ft_strlen(str))
		p.precision = ft_strlen(str);
	if (p.minus == 1)
		count += ft_putstr(str, p);
	if (p.precision >= 0)
		count += ft_putwidth(p.width, p.precision, 0);
	else
		count += ft_putwidth(p.width, ft_strlen(str), 0);
	if (p.minus == 0)
		count += ft_putstr(str, p);
	return (count);
}
