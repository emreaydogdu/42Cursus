/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:21:32 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/25 22:36:34 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putarg(char type, va_list args, t_flags flags)
{
	int		count;

	count = 0;
	if (type == 'c')
		count += ft_putchar_f(va_arg(args, int), flags);
	else if (type == 's') //TODO
		count += ft_putstr_f(va_arg(args, const char *), flags);
	else if (type == 'd' || type == 'i')
		count += ft_putnumbr_f(va_arg(args, int), flags);
	else if (type == 'x' || type == 'X')
		count += ft_puthex_f(va_arg(args, unsigned int),
				type == 'X', flags);
	else if (type == 'u')
		count += ft_putunumbr_f(va_arg(args, unsigned int), flags);
	else if (type == 'p')
		count += ft_putptr_f((unsigned long int) va_arg(args, void *), flags);
	else if (type == '%')
		count += ft_putchar_f('%', flags);
	return (count);
}

int	ft_parse_flags(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flag_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->minus == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flags);
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_istype(str[i]))
		{
			flags->spec = (int)str[i];
			break ;
		}
	}
	return (i);
}

int	ft_parse(char *str, va_list args)
{
	int		i;
	int		x;
	int		count;
	t_flags	flags;

	i = -1;
	count = 0;
	while (str[++i])
	{
		flags = ft_reset_flags(flags);
		if (str[i] == '%' && str[i + 1])
		{
			x = ft_parse_flags(str, i, args, &flags);
			if (flags.spec)
				i = x;
			if (str[i] && flags.spec && ft_istype(str[i]))
				count += ft_putarg(str[i], args, flags);
			else if (str[i])
				count += ft_putchar(str[i]);
		}
		else
			count += ft_putchar(str[i]);
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	char	*str;

	if (!format || *format == '\0')
		return (0);
	str = (char *)format;
	va_start(args, format);
	count = ft_parse(str, args);
	va_end(args);
	return (count);
}
