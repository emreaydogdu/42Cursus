/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/14 23:21:24 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	draw_water(t_map *m)
{
	int	y;
	int	x;

	y = 0;
	while (y <= m->height + 1)
	{
		x = 0;
		while (x <= m->width + 1)
		{
			draw_place(m, x * 32, y * 32, "./src/water.png");
			x++;
		}
		y++;
	}
}

void	draw_land(t_map *m)
{
	int	y;

	y = 1;
	while (y <= m->height)
	{
		if (y == 1)
			draw_line(m, y, "./src/ltl.png", "./src/lt.png", \
			"./src/ltr.png");
		else if (y == m->height)
			draw_line(m, y, "./src/lbl.png", "./src/lb.png", \
			"./src/lbr.png");
		else
			draw_line(m, y, "./src/ll.png", "./src/lm.png", \
			"./src/lr.png");
		if (y == 1)
			draw_line(m, y, "./src/w1.png", "./src/w2.png", \
			"./src/w3.png");
		else if (y == m->height)
			draw_line(m, y, "./src/w5.png", "./src/w2.png", \
			"./src/w6.png");
		else
			draw_line(m, y, "./src/w4.png", "./src/lm.png", \
			"./src/w4.png");
		y++;
	}
}

void	draw_obstacle(t_map *m)
{
	int	x;
	int	y;

	y = 1;
	while (y < m->height - 1)
	{
		x = 1;
		while (x < m->width - 1)
		{
			if (m->map[y][x] == '1')
			{
				if (x % 2 == 0 && y % 2 == 0)
					draw_place(m, (x + 1) * 32, (y + 1) * 32, \
					"./src/o2.png");
				else if (x % 2 == 0 && y % 2 == 1)
					draw_place(m, (x + 1) * 32, (y + 1) * 32, \
					"./src/o1.png");
				else if (x % 2 == 1 && y % 2 == 1)
					draw_place(m, (x + 1) * 32, (y + 1) * 32, \
					"./src/o4.png");
				else
					draw_place(m, (x + 1) * 32, (y + 1) * 32, \
					"./src/o3.png");
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_map *m)
{
	int	x;
	int	y;

	y = 1;
	while (y < m->height - 1)
	{
		x = 1;
		while (x < m->width - 1)
		{
			if (m->map[y][x] == 'P')
			{
				m->player = mlx_texture_to_image(m->window, \
				mlx_load_png("./src/p2.png"));
				mlx_resize_image(m->player, \
				m->player->width * 2, m->player->height * 2);
				mlx_image_to_window(m->window, \
				m->player, (x + 1) * 32, (y + 1) * 32);
				m->pos.x = x;
				m->pos.y = y;
				m->map[y][x] = '0';
				return ;
			}
			x++;
		}
		y++;
	}
}
