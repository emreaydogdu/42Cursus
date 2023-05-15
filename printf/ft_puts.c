/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 00:07:29 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/13 01:11:47 by emaydogd         ###   ########.fr       */
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

int	ft_putnbr(int n)
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
		write(1, "-", 1);
		n *= -1;
		size++;
	}
	if (n > 9)
		size += ft_putnbr(n / 10);
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
