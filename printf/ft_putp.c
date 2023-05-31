/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 15:03:15 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_ptr_len(unsigned long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= 16;
	}
	return (len);
}

static void	ft_putp(unsigned long int n)
{
	if (n >= 16)
	{
		ft_putp(n / 16);
		ft_putp(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else if (n >= 10)
			ft_putchar((n - 10) + 'a');
	}
}

static int	ft_putptr(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_puts("(nil)");
		return (count);
	}
	count += ft_puts("0x");
	ft_putp(n);
	count += ft_ptr_len(n);
	return (count);
}

int	ft_putptr_f(unsigned long int n, t_print p)
{
	int	count;

	count = 0;
	if (n == 0)
		p.width -= ft_strlen("(nil)") - 1;
	else
		p.width -= 2;
	if (p.minus == 1)
		count += ft_putptr(n);
	count += ft_putwidth(p.width, ft_ptr_len(n), 0);
	if (p.minus == 0)
		count += ft_putptr(n);
	return (count);
}
