/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 10:07:49 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_count_digits(long n, t_print *p)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		size++;
	}
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	if (p->plus || p->space)
		size++;
	return (++size);
}

int	ft_putnbr(int n, t_print *p)
{
	int	size;
	int	len;

	size = 0;
	len = ft_count_digits(n, p);
	if ((n == 0 && p->dot) || p->minus)
		p->pad = ' ';
	if (n < 0)
		p->sign = 1;
	else if (p->plus)
		size += ft_pplus(p);
	else if (p->space)
		size += ft_pspace(p);
	if (!p->minus && p->width)
		size += ft_pwidth(len, p);
	if (p->dot && p->precision >= len)
		size += ft_pprecision(len, p);
	size += ft_putnbr_b(n, p);
	if (p->minus && p->width > size)
		size += ft_pwidth(size, p);
	return (size);
}

int	ft_putnbr_b(int n, t_print *p)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n == 0 && p->dot && !p->precision && p->width)
		return ((int) write(1, " ", 1));
	if (n == 0 && p->dot && !p->precision)
		return ((int) write(1, "", 0));
	if (n == -2147483648)
	{
		size += ft_psign(p);
		return (size + (int) write(1, "2147483648", 10));
	}
	if (n < 0)
	{
		size += ft_psign(p);
		n *= -1;
	}
	if (n > 9)
		size += ft_putnbr_b(n / 10, p);
	number = (n % 10) + '0';
	return (size + (int) write(1, &number, 1));
}

int	ft_putunbr(unsigned int n, t_print *p)
{
	int	size;
	int	len;

	size = 0;
	len = ft_count_digits(n, p);
	if (p->minus)
		p->pad = ' ';
	if (n == 0)
	{
		if (p->dot)
			len--;
	}
	if (!p->minus && p->width)
		size += ft_pwidth(len, p);
	if (p->dot && p->precision > len)
		size += ft_pprecision(len, p);
	size += ft_putunbr_b(n, p);
	if (p->minus && p->width)
		size += ft_pwidth(size, p);
	return (size);
}

int	ft_putunbr_b(unsigned int n, t_print *p)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n == 0)
		return ((int) write(1, "", 0));
	if (n > 9)
		size += ft_putunbr_b(n / 10, p);
	number = (n % 10) + '0';
	return (size + (int)write(1, &number, 1));
}
