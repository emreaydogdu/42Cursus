/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:25:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/25 19:15:08 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:01:33 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/25 18:38:36 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putstr(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
	{
		count += ft_putwidth(flags.precision, ft_strlen(str), 0);
		count += ft_print_s_pre(str, flags.precision);
	}
	else
		count += ft_print_s_pre(str, ft_strlen(str));
	return (count);
}

int	ft_putstr_f(const char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (str == NULL && flags.precision >= 0 && flags.precision < 6)
		return (count + ft_putwidth(flags.width, 0, 0));
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_putstr(str, flags);
	if (flags.precision >= 0)
		count += ft_putwidth(flags.width, flags.precision, 0);
	else
		count += ft_putwidth(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += ft_putstr(str, flags);
	return (count);
}

//TODO
int	ft_print_s_pre(const char *str, int precision)
{
	int	count;

	count = 0;
	while (str[count] && count < precision)
		write(1, &str[count++], 1);
	return (count);
}

//TODO
int	ft_print_s(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
