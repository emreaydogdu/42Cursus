/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/21 11:42:52 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return ((int) write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ((int) write(1, "(null)", 6));
	while (s[i])
		i++;
	return ((int) write(1, s, i));
}

int	ft_count_digits(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
	{
		return (11);
	}
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
	return (++size);
}

int	ft_putnbr_b(int n, t_print *p)
{
	int				size;

	size = 0;
	if (!p->plus && p->space && n >= 0)
	{
		//p->width = p->width - 1;
		p->plus = 0;
		p->space = 0;
		size += (int)write(1, " ", 1);
	}
	/*
	if (p->width && !p->minus)
	{
		if (p->plus)
			p->width = p->width - 1;
		p->width = p->width - ft_count_digits(n);
		while (p->width > 0)
		{
			p->width = p->width - 1;
			size += (int)write(1, " ", 1);
		}
	}
	*/
	size += ft_putnbr(n, p);
	/*
	if (p->width && p->minus)
	{
		p->width = p->width - ft_count_digits(n);
		while (p->width > 0)
		{
			p->width = p->width - 1;
			size += (int)write(1, " ", 1);
		}
	}
	 */
	return (size);
}

int	ft_putnbr(int n, t_print *p)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		p->plus = 0;
		p->space = 0;
		write(1, "-", 1);
		n *= -1;
		size++;
	}
	else if (p->plus)
	{
		//p->width = p->width - 1;
		p->plus = 0;
		p->space = 0;
		size += (int)write(1, "+", 1);
	}
	if (n > 9)
		size += ft_putnbr(n / 10, p);
	number = (n % 10) + '0';
	return (size + (int) write(1, &number, 1));
}

int	ft_putunbr(unsigned int n)
{
	unsigned char	number;
	int				size;

	size = 0;
	if (n > 9)
		size += ft_putunbr(n / 10);
	number = (n % 10) + '0';
	return (size + (int)write(1, &number, 1));
}
