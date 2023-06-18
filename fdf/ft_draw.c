/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:31 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/18 18:08:29 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <sys/param.h>
#include <memory.h>

static t_point	ft_project(t_point p, t_map m)
{
	float	prev_y;
	float	prev_x;

	p.x *= m.zoom;
	p.y *= m.zoom;
	p.z *= m.zoom;
	p.x -= (float)m.width * m.zoom / 2;
	p.y -= (float)m.height * m.zoom / 2;
	prev_y = p.y;
	p.y = prev_y * cos(m.persv.a) - (p.z) * sin(m.persv.a);
	p.z = prev_y * sin(m.persv.a) + (p.z) * cos(m.persv.a);

	prev_x = p.x;
	p.x = prev_x * cos(m.persv.b) + (p.z) * sin(m.persv.b);
	p.z = prev_x * cos(m.persv.b) - (p.z) * sin(m.persv.b);

	prev_x = p.x;
	prev_y = p.y;
	p.x = prev_x * cos(m.persv.c) - prev_y * sin(m.persv.c);
	p.y = prev_x * sin(m.persv.c) + prev_y * cos(m.persv.c);

	p.x += m.xoff;
	p.y += m.yoff;
	p.x += (float)m.image->width / 2;
	p.y += (float)m.image->height / 2;
/*
*/
	return (p);
}

static void	ft_draw_line(t_point p1, t_point p2, t_map m)
{
	t_point	ps;
	float	x_step;
	float	y_step;
	float	max;

	p1 = ft_project(p1, m);
	p2 = ft_project(p2, m);
	ps = p1;
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = MAX(ABS(x_step), ABS(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		if (p1.x > 0 && p1.x < 1144 && p1.y > 0 & p1.y < 1000)
			mlx_put_pixel(m.image, (int)p1.x, (int)p1.y, get_color(p1, ps, p2, x_step > y_step));
		p1.x += x_step;
		p1.y += y_step;
	}
}

void	ft_draw_image(t_map *m)
{
	int	y;
	int	x;

	if (m->image != NULL)
		mlx_delete_image(m->window, m->image);
	m->image = mlx_new_image(m->window, 1144, 1000);
	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (++x < m->width)
		{
			if (x < m->width - 1)
				ft_draw_line(m->map[y][x], m->map[y][x + 1], *m);
			if (y < m->height - 1)
				ft_draw_line(m->map[y][x], m->map[y + 1][x], *m);
		}
	}
	mlx_image_to_window(m->window, m->image, 256, 0);
}
