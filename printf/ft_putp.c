/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 13:47:19 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ptr_len(unsigned long int n)
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

void	ft_print_adr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_adr(n / 16);
		ft_print_adr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_putchar(n + '0');
		else if (n >= 10)
			ft_putchar((n - 10) + 'a');
	}
}

int	ft_putptr(unsigned long int n)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count += ft_print_s("(nil)");
		return (count);
	}
	count += ft_print_s("0x");
	ft_print_adr(n);
	count += ft_ptr_len(n);
	return (count);
}

int	ft_putptr_f(unsigned long int n, t_flags flags)
{
	int	count;

	count = 0;
	if (n == 0)
		flags.width -= ft_strlen("(nil)") - 1;
	else
		flags.width -= 2;
	if (flags.minus == 1)
		count += ft_putptr(n);
	count += ft_putwidth(flags.width, ft_ptr_len(n), 0);
	if (flags.minus == 0)
		count += ft_putptr(n);
	return (count);
}
