/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:31 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/15 15:51:47 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <sys/param.h>
#include <memory.h>

t_point	*ft_point(int x, int y, int z, int color, t_map m)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		mlx_terminate(m.window);
	point->x = (float)x;
	point->y = (float)y;
	point->z = (float)z;
	point->color = (!point->color && point->z) ? 0xFFFFFFFF : 0xFF1B30;
	return (point);
}

static t_point	ft_project(t_point p, t_map m)
{
	int	prev_y;
	int	prev_x;
	int	prev_z;

	p.x *= (float)m.zoom;
	p.y *= (float)m.zoom;
	p.z *= (float)m.zoom;

	p.x += 1144 / 2 - m.width * m. zoom /2;
	p.y += 1000 / 2 - m.height * m. zoom /2;

	prev_y = p.y;
	p.y = prev_y * cos(m.persv->a) + (p.z) * sin(m.persv->a);
	p.z = -prev_y * sin(m.persv->a) + (p.z) * cos(m.persv->a);

	prev_x = p.x;
	p.x = prev_x * cos(m.persv->b) + (p.z) * sin(m.persv->b);
	p.z = -prev_x * sin(m.persv->b) + (p.z) * cos(m.persv->b);

	prev_x = p.x;
	prev_y = p.y;
	p.x = prev_x * cos(m.persv->c) - prev_y * sin(m.persv->c);
	p.y = prev_x * sin(m.persv->c) + prev_y * cos(m.persv->c);

	p.x += m.xoff;
	p.y += m.yoff;
	return (p);
}

static void	ft_draw_line(t_point p1, t_point p2, t_map m)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		if (p1.x > 0 && p1.x < 1144 && p1.y > 0 & p1.y < 1000)
		{
			mlx_put_pixel(m.image, p1.x, p1.y, p1.color);
		}
		
		p1.x += x_step;
		p1.y += y_step;
	}
}

void	ft_draw_image(t_map *m)
{
	int	y;
	int	x;

	if (m->image->enabled == 0)
		mlx_delete_image(m->window, m->image);
	m->image = mlx_new_image(m->window, 1144, 1000);
	y = 0;
	while (y < m->height)
	{
		x = 0;
		while (x < m->width)
		{
			if (x < m->width - 1)
				ft_draw_line(ft_project(m->map[y][x], *m), ft_project(m->map[y][x + 1], *m), *m);
			if (y < m->height - 1)
				ft_draw_line(ft_project(m->map[y][x], *m), ft_project(m->map[y + 1][x], *m), *m);
			x++;
		}
		y++;
	}
	mlx_image_to_window(m->window, m->image, 256, 0);
}
