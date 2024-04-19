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

float	ft_strtof(const char *str)
{
	float val = 0;
	int afterdot=0;
	float scale=1;
	int neg = 1;

	if (*str == '-')
	{
		str++;
		neg = -1;
	}
	while (*str) {
		if (afterdot) {
			scale = scale/10;
			val = val + (*str-'0')*scale;
		} else {
			if (*str == '.')
				afterdot++;
			else
				val = val * 10.0 + (*str - '0');
		}
		str++;
	}
	return ((float)neg * (float)val);
}
