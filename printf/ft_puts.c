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
//#include "ft_printf.h"
# include <unistd.h>

void	ft_putnbr(int n)
{
	unsigned char	number;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	number = (n % 10) + '0';
	write(1, &number, 1);
}

void	ft_putunbr(unsigned int n)
{
	unsigned char	number;

	if (n > 9)
		ft_putunbr(n / 10);
	number = (n % 10) + '0';
	write(1, &number, 1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

