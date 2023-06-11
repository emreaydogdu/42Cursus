/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:26:28 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/11 22:30:05 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <sys/param.h>

static void	iso(float *x, float *y, int z, float angle)
{
	float	previous_x;
	float	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(angle);
	*y = -z + (previous_x + previous_y) * sin(angle);
}

static t_point	*ft_point(int x, int y, t_map m)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		mlx_terminate(m.window);
	point->x = (float)x;
	point->y = (float)y;
	point->z = (float)m.map[y][x];
	point->color = (!point->color && point->z) ? 0xffff00ff : 0xffffffff;
	return (point);
}

static t_point	*ft_project(t_point *p, t_map m)
{
	int	prev_y;
	int	prev_x;
	int	prev_z;

	//p->x += m.xoff;
	//p->y += m.yoff;
	p->x *= m.zoom;
	p->y *= m.zoom;
	p->z *= m.zoom;

	//p->x -= (float)(m.width * m.zoom) / 2;
	//p->y -= (float)(m.height * m.zoom) / 2;

	prev_y = p->y;
	p->y = prev_y * cos(m.persv->a) + (p->z) * sin(m.persv->a);
	p->z = -prev_y * sin(m.persv->a) + (p->z) * cos(m.persv->a);

	prev_x = p->x;
	p->x = prev_x * cos(m.persv->b) + (p->z) * sin(m.persv->b);
	p->z = -prev_x * sin(m.persv->b) + (p->z) * cos(m.persv->b);

	prev_x = p->x;
	prev_y = p->y;
	p->x = prev_x * cos(m.persv->c) - prev_y * sin(m.persv->c);
	p->y = prev_x * sin(m.persv->c) + prev_y * cos(m.persv->c);

	return (p);
}

static void	ft_draw_line(t_point *p1, t_point *p2, t_map m)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = p2->x - p1->x;
	y_step = p2->y - p1->y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(p1->x - p2->x) || (int)(p1->y - p2->y))
	{
		mlx_put_pixel(m.image, (int)p1->x + 200, (int)p1->y, p1->color);
		p1->x += x_step;
		p1->y += y_step;
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
				ft_draw_line(ft_project(ft_point(x, y, m), m), ft_project(ft_point(x + 1, y, m), m), m);
			if (y < m.height - 1)
				ft_draw_line(ft_project(ft_point(x, y, m), m), ft_project(ft_point(x, y + 1, m), m), m);
			x++;
		}
		y++;
	}
}
