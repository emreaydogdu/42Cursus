/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/24 16:32:40 by emaydogd         ###   ########.fr       */
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
	if (n == 0 && p->dot && !p->precision)
		return (0);
	if (n < 0)
	{
		p->sign = 1;
		size++;
	}
	else if (p->plus)
		size += ft_pplus(p);
	else if (p->space)
		size += ft_pspace(p);
	if ((!p->minus && p->width) || p->dot)
		size += ft_print_width(len, p);
	size += ft_putnbr_b(n, p);
	if (p->minus && p->width)
		size += ft_print_width(len, p);
	return (size);
}

int	ft_putnbr_b(int n, t_print *p)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n == -2147483648)
	{
		if (p->sign)
		{
			p->sign = 0;
			write(1, ".", 1);
		}
		return ((int) write(1, "2147483648", 10));
	}
	if (n < 0)
	{
		p->sign = 0;
		write(1, "-", 1);
		n *= -1;
		size++;
	}
	if (n > 9)
		size += ft_putnbr_b(n / 10, p);
	number = (n % 10) + '0';
	return (size + (int) write(1, &number, 1));
}

int	ft_putunbr(unsigned int n, t_print *p)
{
	int				size;

	size = 0;
	if (n == 0 && p->dot && !p->precision)
		return (0);
	if ((!p->minus && p->width) || p->dot)
		size += ft_print_width(ft_count_digits(n, p), p);
	size += ft_putunbr_b(n, p);
	if (p->minus && p->width)
		size += ft_print_width(ft_count_digits(n, p), p);
	return (size);
}

int	ft_putunbr_b(unsigned int n, t_print *p)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n > 9)
		size += ft_putunbr_b(n / 10, p);
	number = (n % 10) + '0';
	return (size + (int)write(1, &number, 1));
}
