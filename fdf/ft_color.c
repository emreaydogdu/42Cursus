/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:06:24 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/17 17:11:44 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

float	percent(float start, float end, float current)
{
	float	placement;
	float	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0f);
	else
		return (placement / distance);
}

int	get_default_color(int z)
{
	double	percentage;

	percentage = percent(0, 10, z);
	if (percentage < 0.2)
		return (COLOR_DISCO);
	else if (percentage < 0.4)
		return (COLOR_BRICK_RED);
	else if (percentage < 0.6)
		return (COLOR_FLAMINGO);
	else if (percentage < 0.8)
		return (COLOR_JAFFA);
	else
		return (COLOR_SAFFRON);
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(t_point current, t_point start, t_point end, int delta)
{
	int		red;
	int		green;
	int		blue;
	int		white;
	double	p;

	if (current.color == end.color)
		return (current.color);
	if (delta)
		p = percent(start.x, end.x, current.x);
	else
		p = percent(start.y, end.y, current.y);
	red = get_light((start.color >> 24) & 0xFF, (end.color >> 24) & 0xFF, p);
	green = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, p);
	blue = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, p);
	white = get_light(start.color & 0xFF, end.color & 0xFF, p);
	return ((red << 24) | (green << 16) | (blue << 8) | white);
}
