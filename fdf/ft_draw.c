/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:26:28 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/11 16:27:18 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <sys/param.h>

static void	iso(float *x, float *y, int z)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

static void	ft_draw_line(float x, float y, float x1, float y1, t_map m)
{
	float	x_step;
	float	y_step;
	int		z;
	int		z1;
	int		max;
	int		color;

	z = m.map[(int)y][(int)x];
	z1 = m.map[(int)y1][(int)x1];
	x *= 20.0f;
	x1 *= 20.0f;
	y *= 20.0f;
	y1 *= 20.0f;
	iso(&x, &y, z * 2);
	iso(&x1, &y1, z1 * 2);
	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD (y_step));
	x_step /= max;
	y_step /= max;
	color = (z) ? 0xffff00ff : 0xffffffff;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_put_pixel(m.image, x+200, y, color);
		x += x_step;
		y += y_step;
	}
}

void	ft_draw(t_map m)
{
	int	y;
	int	x;

	y = 0;
	while (y < m.height)
	{
		x = 0;
		while (x < m.width)
		{
			if (x < m.width - 1)
				ft_draw_line(x, y, x + 1, y, m);
			if (y < m.height - 1)
				ft_draw_line(x, y, x, y + 1, m);
			x++;
		}
		y++;
	}
}

