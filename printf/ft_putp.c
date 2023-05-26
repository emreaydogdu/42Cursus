/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 22:41:25 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:49:21 by mcombeau          #+#    #+#             */
/*   Updated: 2021/12/13 12:13:11 by mcombeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		count += ft_print_s(PTRNULL);
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
		flags.width -= ft_strlen(PTRNULL) - 1;
	else
		flags.width -= 2;
	if (flags.minus == 1)
		count += ft_putptr(n);
	count += ft_putwidth(flags.width, ft_ptr_len(n), 0);
	if (flags.minus == 0)
		count += ft_putptr(n);
	return (count);
}
