/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions_h.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 13:52:41 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isspec(c));
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_isspec(int c)
{
	return (c == '-' || c == '0' || c == '.' || c == '*'
		|| c == '#' || c == ' ' || c == '+');
}

int	ft_istype(int c)
{
	return (c == 'c' || c == 's' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == 'p' || c == '%');
}

int	ft_putwidth(int width, int size, int zero)
{
	int	count;

	count = 0;
	while (width-- - size > 0)
		if (zero)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	return (count);
}
