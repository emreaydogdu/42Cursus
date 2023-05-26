/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcombeau <mcombeau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:44:50 by mcombeau          #+#    #+#             */
/*   Updated: 2023/05/25 18:19:20 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(int c)
{
	return (ft_istype(c) || ft_isdigit(c) || ft_isspec(c));
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
