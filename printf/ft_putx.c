/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 10:12:18 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/* counting length */
int	ft_putptr_c(unsigned long n)
{
	int				size;

	size = 0;
	if (n >= 16)
		size += ft_putptr_c(n / 16);
	return (size + 1);
}

/* x && X */
int	ft_puthex(unsigned int n, int caps, t_print *p)
{
	int	i;
	int	len;

	i = 0;
	len = ft_putptr_c(n);
	p->pad = ' ';
	if ((!p->minus && p->width))
		i += ft_pwidth(len, p);
	if (p->dot && p->precision > len)
		i += ft_pprecision(len, p);
	i += ft_puthex_h(n, caps, p);
	if (p->minus && p->width)
		i += ft_pwidth(i, p);
	return (i);
}

int	ft_puthex_h(unsigned int n, int caps, t_print *p)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n == 0 && p->dot && !p->precision)
		return ((int) write(1, "", 0));
	if (p->hash)
	{
		size += (int)write(1, "0", 1);
		size += (int)write(1, &caps, 1);
		p->hash = 0;
	}
	if (n >= 16)
		size += ft_puthex_h(n / 16, caps, p);
	if (caps == 'X')
		number = "0123456789ABCDEF"[n % 16];
	else
		number = "0123456789abcdef"[n % 16];
	return (size + (int)write(1, &number, 1));
}

/* p */
int	ft_putptr(unsigned long n, t_print *p)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		if (!p->minus)
			i += ft_print_width(5, p);
		i += (int) write(1, "(nil)", 5);
		if (p->minus)
			i += ft_print_width(5, p);
		return (i);
	}
	else
	{
		if (!p->minus && p->width)
			i += ft_print_width(ft_putptr_c(n) + 2, p);
		i += (int)write(1, "0x", 2);
		i += ft_putptr_h(n);
		if (p->minus && p->width)
			i += ft_print_width(ft_putptr_c(n) + 2, p);
		return (i);
	}
}

int	ft_putptr_h(unsigned long n)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n >= 16)
		size += ft_putptr_h(n / 16);
	number = "0123456789abcdef"[n % 16];
	return (size + (int)write(1, &number, 1));
}
