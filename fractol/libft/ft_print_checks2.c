/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_checks2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:36 by fzucconi          #+#    #+#             */
/*   Updated: 2023/11/22 18:58:35 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_print_x(char *format, va_list arg, int fd)
{
	unsigned int	buf;

	buf = 0;
	if (*(format + 1) == 'x')
	{
		buf = va_arg(arg, unsigned);
		if (buf == 0)
		{
			ft_putstr_fd("0", fd);
			return (1);
		}
		return (ft_puthexa_l_fd(buf, fd));
	}
	return (0);
}

int	ft_check_print_u_x(char *format, va_list arg, int fd)
{
	unsigned int	buf;

	buf = 0;
	if (*(format + 1) == 'X')
	{
		buf = va_arg(arg, unsigned);
		if (buf == 0)
		{
			ft_putstr_fd("0", fd);
			return (1);
		}
		return (ft_puthexa_u_fd(buf, fd));
	}
	return (0);
}

int	ft_check_print_p(char *format, va_list arg, int fd)
{
	unsigned long int	buf;

	buf = 0;
	if (*(format + 1) == 'p')
	{
		buf = (unsigned long int)va_arg(arg, void *);
		if (buf == 0)
		{
			ft_putstr_fd("(nil)", fd);
			return (5);
		}
		ft_putstr_fd("0x", fd);
		return (ft_putptr_fd(buf, fd) + 2);
	}
	return (0);
}
