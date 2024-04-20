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
#include "so_long.h"

void	draw_place(t_map *m, int x, int y, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(path);
	img = mlx_texture_to_image(m->window, texture);
	mlx_resize_image(img, img->width * 2, img->height * 2);
	mlx_image_to_window(m->window, img, x, y);
	mlx_delete_texture(texture);
}

void	draw_line(t_map *m, int y, char *path, char *path2, char *path3)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
	int				x;

	x = 1;
	while (x <= m->width)
	{
		if (x == 1)
			texture = mlx_load_png(path);
		else if (x == m->width)
			texture = mlx_load_png(path3);
		else
			texture = mlx_load_png(path2);
		img = mlx_texture_to_image(m->window, texture);
		mlx_resize_image(img, img->width * 2, img->height * 2);
		mlx_image_to_window(m->window, img, x * 32, y * 32);
		mlx_delete_texture(texture);
		x++;
	}
}

void	draw_water(t_map *m)
{
	int	y;
	int	x;

	y = -1;
	while (++y <= m->height + 1)
	{
		x = -1;
		while (++x <= m->width + 1)
			draw_place(m, x * 32, y * 32, "./src/water.png");
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

void	draw_wall(int x, int y, t_map *m)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./src/o1.png");
	m->wall1 = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./src/o2.png");
	m->wall2 = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./src/o3.png");
	m->wall3 = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./src/o4.png");
	m->wall4 = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
	if (x / 32 % 2 == 0 && y / 32 % 2 == 0)
		mlx_image_to_window(m->window, m->wall1, x, y);
	else if (x / 32 % 2 == 0 && y / 32 % 2 == 1)
		mlx_image_to_window(m->window, m->wall2, x, y);
	else if (x / 32 % 2 == 1 && y / 32 % 2 == 1)
		mlx_image_to_window(m->window, m->wall3, x, y);
	else
		mlx_image_to_window(m->window, m->wall4, x, y);
}
