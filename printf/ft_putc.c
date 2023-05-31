/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:46:24 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 15:01:52 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_putchar_f(char c, t_print p)
{
	int		count;

	count = 0;
	if (p.minus == 1)
		count += ft_putchar(c);
	count += ft_putwidth(p.width, 1, p.zero);
	if (p.minus == 0)
		count += ft_putchar(c);
	return (count);
}
