/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putshex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:13:41 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/13 00:54:24 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_puthex(int n, int caps)
{
	char	number;

	if (n > 16)
		ft_puthex(n / 16, caps);
	if (caps)
		number = "0123456789ABCDEF"[n % 16];
	else
		number = "0123456789abcdef"[n % 16];
	write(1, &number, 1);
}

void	ft_print_adress_hex(char *p)
{
	intptr_t	x;
	size_t		i;
	char		buf[9];

	x = (intptr_t)p;
	i = 0;
	while (i <= 8)
	{
		buf[i] = "0123456789abcdef"[(x >> ((8 - i) * 4)) & 0xf];
		i++;
	}
	write(1, "0x", 2);
	write(1, buf, sizeof(buf));
}
