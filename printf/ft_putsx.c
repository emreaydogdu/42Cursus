/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/21 11:49:17 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_puthex(unsigned int n, int caps, t_print *p)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (p->hash)
	{
		size += (int)write(1, "0x", 2);
		p->hash = 0;
	}
	if (n >= 16)
		size += ft_puthex(n / 16, caps, p);
	if (caps == 'X')
		number = "0123456789ABCDEF"[n % 16];
	else
		number = "0123456789abcdef"[n % 16];
	return (size + (int)write(1, &number, 1));
}

int	ft_puthexp(unsigned long n)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n >= 16)
		size += ft_puthexp(n / 16);
	number = "0123456789abcdef"[n % 16];
	return (size + (int)write(1, &number, 1));
}

int	ft_puthexph(unsigned long n)
{
	if (n == 0)
		return ((int) write(1, "(nil)", 5));
	else
	{
		write(1, "0x", 2);
		return (2 + ft_puthexp(n));
	}
}