/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/24 22:43:48 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c, t_print *p)
{
	int	i;

	i = 0;
	if (!p->minus && p->width)
		i += ft_pwidth(1, p);
	i += (int) write(1, &c, 1);
	if (p->minus && p->width)
		i += ft_pwidth(1, p);
	return (i);
}

int	ft_putstr(char *s, t_print *p)
{
	int	i;
	int	len;

	i = 0;
	if (s == NULL)
	{
		if (p->dot && p->precision < 6)
			return (0);
		p->precision = 0;
		if (!p->minus)
			i += ft_print_width(6, p);
		i += (int) write(1, "(null)", 6);
		if (p->minus)
			i += ft_print_width(6, p);
		return (i);
	}
	len = ft_strlen(s);
	if (p->dot && p->precision < len)
		len = p->precision;
	if (!p->minus && p->width)
		i += ft_pwidth(len, p);
	if (p->dot && p->precision > len)
		i += ft_pprecision(len, p);
	i += (int)write(1, s, len);
	if (p->minus && p->width)
		i += ft_pwidth(i, p);
	return (i);
}
