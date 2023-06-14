/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 14:05:31 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/14 22:02:48 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <sys/param.h>
#include <memory.h>

static void	iso(float *x, float *y, int z, float angle)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(angle);
	*y = -z + (previous_x + previous_y) * sin(angle);
}

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
	p.x -= 350;
	p.y -= 250;
	//p.x -= (float)(m.width * m.zoom) / 2;
	//p.y -= (float)(m.height * m.zoom) / 2;

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
/*



 */
	return (p);
}

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int	get_color(int curx, int cury, t_point start, t_point end)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (curx > cury)
		percentage = percent(start.x, end.x, curx);
	else
		percentage = percent(start.y, end.y, cury);
	red = get_light((start.color >> 16) & 0xFF, (end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF, (end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

static void	ft_draw_line(t_point p1, t_point p2, t_map m)
{
	float	x_step;
	float	y_step;
	int		max;

	//p1.x *= m.zoom;
	//p1.y *= m.zoom;
	//p2.x *= m.zoom;
	//p2.y *= m.zoom;
	//iso(&p1.x, &p1.y, p1.z, m.angle);
	//iso(&p2.x, &p2.y, p2.z, m.angle);

	p1.x += 700;
	p1.y += 500;
	p2.x += 700;
	p2.y += 500;
	x_step = p2.x - p1.x;
	y_step = p2.y - p1.y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y))
	{
		mlx_put_pixel(m.image, p1.x, p1.y, p1.color);
		p1.x += x_step;
		p1.y += y_step;
	}
}

void	ft_draw_image(t_map *m)
{
	int	y;
	int	x;

	if (m->image->enabled == 1)
		mlx_delete_image(m->window, m->image);
	//m->image = mlx_new_image(m->window, m->width * m->zoom, m->height * m->zoom);
	m->image = mlx_new_image(m->window, 1400, 1000);
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
	mlx_image_to_window(m->window, m->image, 0, 0);
}
