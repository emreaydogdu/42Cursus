/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/14 23:28:42 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	free_mem(t_map *m)
{
	int i = -1;
	while (++i < m->height)
	{
		free(m->map[i]);
		free(m->mapcpy[i]);
	}
	free(m->map);
	free(m->mapcpy);
	//free(m->window);
	//free(m);
}

void	parse_textures(t_map *m)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./src/p2.png");
	m->player = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./src/collect.png");
	m->collectibles = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./src/end1.png");
	m->end1 = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./src/end2.png");
	m->end2 = mlx_texture_to_image(m->window, texture);
	mlx_delete_texture(texture);
}

void	draw_game(t_map *m)
{
	int		x;
	int		y;
	t_pos	pos_p;
	t_pos	pos;

	y = 0;
	while (++y < m->height - 1)
	{
		x = 0;
		while (++x < m->width - 1)
		{
			pos = (t_pos){(x + 1) * 32, (y + 1) * 32};
			if (m->map[y][x] == 'P')
			{
				m->map[y][x] = '0';
				pos_p = (t_pos){(x + 1) * 32, (y + 1) * 32};
			}
			if (m->map[y][x] == 'C')
				mlx_image_to_window(m->window, m->collectibles, pos.x, pos.y);
			if (m->map[y][x] == '1')
				draw_wall(pos.x, pos.y, m);
			if (m->map[y][x] == 'E')
				mlx_image_to_window(m->window, m->end1, pos.x, pos.y);
			if (m->map[y][x] == 'E')
			{
				mlx_image_to_window(m->window, m->end2, pos.x, pos.y);
				m->end2->instances[0].enabled = false;
			}
		}
	}
	mlx_image_to_window(m->window, m->player, pos_p.x, pos_p.y);
}

void	init_map(t_map *m)
{
	m->map = NULL;
	m->mapcpy = NULL;
	m->window = NULL;
	m->player = NULL;
	m->collectibles = NULL;
	m->end1 = NULL;
	m->end2 = NULL;
	m->wall1 = NULL;
	m->wall2 = NULL;
	m->wall3 = NULL;
	m->wall4 = NULL;
	m->collected = 0;
	m->ccount = 0;
	m->pcount = 0;
	m->ecount = 0;
	m->moves = 0;
	m->width = 0;
	m->height = 0;
}

int	main(int argc, char **argv)
{
	t_map	m;

	if (argc != 2)
		ft_error(ERR_ARGS);
	init_map(&m);
	ft_map_parse(argv[1], &m);
	m.window = mlx_init(m.width * 32 + 64, m.height * 32 + 64,"so_long", false);
	//mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	draw_water(&m);
	draw_land(&m);
	parse_textures(&m);
	draw_game(&m);
	mlx_key_hook(m.window, &keyhook, &m);
	mlx_close_hook(m.window, &ft_close_hook, &m);
	mlx_loop(m.window);
	return (EXIT_SUCCESS);
}
