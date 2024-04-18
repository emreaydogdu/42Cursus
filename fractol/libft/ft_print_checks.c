/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:06:36 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 13:34:18 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_print_c(char *format, va_list arg, int fd)
{
	if (*(format + 1) == 'c')
	{
		ft_putchar_fd(va_arg(arg, int), fd);
		return (1);
	}
	return (0);
}

int	ft_check_print_s(char *format, va_list arg, int fd)
{
	char	*str;

	str = 0;
	if (*(format + 1) == 's')
	{
		str = va_arg(arg, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", fd);
			return (6);
		}
		ft_putstr_fd(str, fd);
		return (ft_strlen(str));
	}
	return (0);
}

int	ft_check_print_d_i(char *format, va_list arg, int fd)
{
	int	num;

	num = 0;
	if (*(format + 1) == 'd'
		|| *(format + 1) == 'i')
	{
		num = va_arg(arg, int);
		ft_putnbr_fd(num, fd);
		return (ft_numlen(num));
	}
	return (0);
}

int	ft_check_print_u(char *format, va_list arg, int fd)
{
	int	num;

	num = 0;
	if (*(format + 1) == 'u')
	{
		num = va_arg(arg, int);
		return (ft_putunbr_fd(num, fd));
	}
	return (0);
}

int	ft_check_print_perc(char *format, int fd)
{
	if (*(format + 1) == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
	return (0);
}
