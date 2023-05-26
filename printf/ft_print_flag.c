/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:11:01 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/25 18:45:12 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putwidth(int width, int size, int zero)
{
	int	count;

	count = 0;
	while (width-- - size > 0)
	{
		if (zero)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
	}
	return (count);
}
