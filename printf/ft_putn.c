/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 15:57:27 by emaydogd         ###   ########.fr       */
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
		p->sign = "-";
		//size++;
	}
	//else if (p->sign == " " || p->sign == "+")
	//	size++;
	while (n / 10)
	{
		n /= 10;
		size++;
	}
	return (++size);
}

int	ft_putnbr(int n, t_print *p)
{
	int	i;
	int	size;
	int	len;
	int	width;
	int precision;

	size = 0;
	i = 0;
	len = ft_count_digits(n, p);
	width = ft_calc_width(len, p);
	precision = ft_calc_precision(len, p);
	//printf("[%d]->[%d][%d][%d]", ft_calc_precision(len, p), p->width, p->precision, ft_strlen(p->sign));
	if (p->minus)
	{
		size += ft_psign(p);
		if (p->dot && p->precision > len)
			size += ft_pprecision(precision, p);
		size += ft_putnbr_b(n, p);
		if (p->minus && p->width)
			size += ft_pwidth(width, p);
	}
	else if (p->zero && p->dot && p->precision)
	{
		p->pad = ' ';
		if (!p->minus && p->width)
			size += ft_pwidth(width, p);
		size += ft_psign(p);
		if (p->dot && p->precision)
			size += ft_pprecision(precision, p);
		size += ft_putnbr_b(n, p);
	}
	else if (p->zero)
	{
		p->pad = '0';
		size += ft_psign(p);
		if (!p->minus && p->width)
			size += ft_pwidth(width, p);
		if (p->dot && p->precision > len)
			size += ft_pprecision(len - i, p);
		size += ft_putnbr_b(n, p);
	}
	else if (!p->zero)
	{
		if (!p->minus && p->width)
			size += ft_pwidth(width, p);
		size += ft_psign(p);
		if (p->dot && p->precision > len)
			size += ft_pprecision(precision, p);
		size += ft_putnbr_b(n, p);
	}
	/*
	if (p->plus || p->space)
		len++;
	else if (p->plus)
		i += ft_pplus(p);
	else if (p->space)
		i += ft_pspace(p);
	size += ft_putnbr_b(n, p);
	size += ft_putnbr_b(n, p);
	if (p->minus && p->width > size)
		size += ft_pwidth(size, p);
	 */
	return (size + i);
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
		return (size + (int) write(1, "2147483648", 10));
	}
	if (n < 0)
	{
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
	if (n == 0 && p->dot && !p->precision)
		return ((int) write(1, "", 0));
	if (n > 9)
		size += ft_putunbr_b(n / 10, p);
	number = (n % 10) + '0';
	return (size + (int)write(1, &number, 1));
}

int	ft_calc_width(int len, t_print *p)
{
	if (p->width && p->dot && p->precision)
		return (p->width - p->precision - ft_strlen(p->sign));
	else if (p->width)
		return (p->width - len - ft_strlen(p->sign));
	else
		return (0);
}
int	ft_calc_precision(int len, t_print *p)
{
	if (p->dot && !p->precision)
		return (0);
	else if (p->dot && p->precision && p->precision > len)
		return (p->precision - len);
	else
		return (0);
}