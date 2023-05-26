/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 18:46:37 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:01:33 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/25 18:25:41 by emaydogd         ###   ########.fr       */
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
