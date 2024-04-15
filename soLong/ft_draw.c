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

void	draw_end(t_map *m)
{
	int	x;
	int	y;
	mlx_texture_t	*texture;

	y = 1;
	while (y < m->height - 1)
	{
		x = 1;
		while (x < m->width - 1)
		{
			if (m->map[y][x] == 'E')
			{
				m->end = malloc(sizeof(t_end));
				m->end2 = malloc(sizeof(t_end));
				texture = mlx_load_png("./src/end1.png");
				m->end->img = mlx_texture_to_image(m->window, texture);
				mlx_resize_image(m->end->img, m->end->img->width * 2, \
				m->end->img->height * 2);
				mlx_image_to_window(m->window, m->end->img, \
				(x + 1) * 32, (y + 1) * 32);
				mlx_delete_texture(texture);
				texture = mlx_load_png("./src/end2.png");
				m->end2->img = mlx_texture_to_image(m->window, texture);
				mlx_resize_image(m->end2->img, m->end2->img->width * 2, \
				m->end2->img->height * 2);
				mlx_image_to_window(m->window, m->end2->img, \
				(x + 1) * 32, (y + 1) * 32);
				mlx_delete_texture(texture);
				m->end->pos = (t_pos){x, y};
				m->end2->pos = (t_pos){x, y};
				m->end2->img->enabled = false;
			}
			x++;
		}
		y++;
	}
}

void	draw_collect(t_map *m)
{
	int				x;
	int				y;
	int				i;
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	y = 1;
	i = 0;
	m->collections = malloc(sizeof(t_col *) * m->ccount + 1);
	while (y < m->height - 1)
	{
		x = 1;
		while (x < m->width - 1)
		{
			if (m->map[y][x] == 'C')
			{
				m->collections[i] = malloc(sizeof(t_col));
				m->collections[i]->x = x;
				m->collections[i]->y = y;
				texture = mlx_load_png("./src/collect.png");
				img = mlx_texture_to_image(m->window, texture);
				mlx_resize_image(img, img->width * 2, img->height * 2);
				mlx_image_to_window(m->window, img, (x + 1) * 32, (y + 1) * 32);
				mlx_delete_texture(texture);
				m->collections[i]->col = img;
				i++;
			}
			x++;
		}
		y++;
	}
}
