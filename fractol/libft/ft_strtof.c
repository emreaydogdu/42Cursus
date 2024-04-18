/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtof.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:18:41 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/05 16:30:51 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	check_sign(const char **str, int *sign)
{
	if (**str == '-')
	{
		*sign = -1;
		(*str)++;
	}
	else if (**str == '+')
		(*str)++;
}

float	ft_strtof(const char *str)
{
	float	result;
	int		sign;
	float	decimal_multiplier;

	result = 0.0f;
	sign = 1;
	decimal_multiplier = 0.1f;
	check_sign(&str, &sign);
	while (*str >= '0' && *str <= '9')
		result = result * 10.0f + (*(str++) - '0');
	if (*str == '.')
	{
		str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result + (*(str++) - '0') * decimal_multiplier;
			decimal_multiplier *= 0.1f;
		}
	}
	return ((float)sign * (float)((int)result));
}
