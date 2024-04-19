/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:26:27 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/11 11:50:12 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	check_neg(const char *str)
{
	int	neg;

	neg = 1;
	if (*str == '-')
	{
		neg = -1;
	}
	return (neg);
}

float	ft_strtof(const char *str)
{
	float	val;
	int		afterdot;
	float	scale;
	int		neg;

	neg = check_neg(str);
	scale = 1;
	afterdot = 0;
	val = 0;
	while (*(++str))
	{
		if (afterdot)
		{
			scale = scale / 10;
			val = val + (*str - '0') * scale;
		}
		else
		{
			if (*str == '.')
				afterdot++;
			else
				val = val * 10.0 + (*str - '0');
		}
	}
	return ((float)neg * (float)val);
}
