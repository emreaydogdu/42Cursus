/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:46:24 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 13:51:45 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putchar_f(char c, t_flags flags)
{
	int		count;

	count = 0;
	if (flags.minus == 1)
		count += ft_putchar(c);
	count += ft_putwidth(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += ft_putchar(c);
	return (count);
}
