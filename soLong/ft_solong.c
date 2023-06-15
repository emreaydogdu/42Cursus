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
#include <memory.h>
#include "fdf.h"

void	p_background(t_map m)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./src/battleground.png");
	img = mlx_texture_to_image(m.window, texture);
	mlx_resize_image(img, m.width * 60 + 10, m.height * 60 + 10);
	mlx_image_to_window(m.window, img, 0, 0);
}
void	p_wall(t_map m, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./src/Bush_simple1_1s.png");
	img = mlx_texture_to_image(m.window, texture);
	mlx_resize_image(img, img->width * 2.2, img->height * 2.2);
	mlx_image_to_window(m.window, img, x, y);
}
void	p_collect(t_map m, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./src/collect4.png");
	img = mlx_texture_to_image(m.window, texture);
	mlx_resize_image(img, img->width * 1.8 + 5, img->height * 1.8 + 15);
	mlx_image_to_window(m.window, img, x, y);
}
void	p_player(t_map *m, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./src/right.png");
	if (m->player->enabled == 1)
		mlx_delete_image(m->window, m->player);
	m->player = mlx_texture_to_image(m->window, texture);
	mlx_resize_image(m->player, m->player->width * 2.2, m->player->height * 2.2);
	mlx_image_to_window(m->window, m->player, x, y);
}
void	p_end(t_map m, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./src/end.png");
	img = mlx_texture_to_image(m.window, texture);
	mlx_resize_image(img, img->width * 0.4, img->height * 0.4);
	mlx_image_to_window(m.window, img, x - 15, y - 18);
}
void	p_walls(t_map m)
{
	int	x;
	int	y;

	y = 0;
	while (y < m.height)
	{
		x = 0;
		while (x < m.width)
		{
			if (m.map[y][x].z == '1')
				p_wall(m, x * 60, y * 60);
			if (m.map[y][x].z == 'P')
				p_player(&m, x * 60, y * 60);
			if (m.map[y][x].z == 'C')
				p_collect(m, x * 60, y * 60);
			if (m.map[y][x].z == 'E')
				p_end(m, x * 60, y * 60);
			x++;
		}
		y++;
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*m;

	m = param;
	printf("%d", m->player->enabled == 0);
	if (mlx_is_key_down(m->window, MLX_KEY_UP))
		if (m->player->enabled == 0)
			mlx_delete_image(m->window, m->player);
}

int	main(int argc, char **argv)
{
	t_map		*m;

	m = malloc(sizeof(t_map));
	if (argc == 2)
	{
		ft_parse_map(argv[1], m);
		ft_print_map(*m);
		m->window = mlx_init(m->width * 60 + 10, m->height * 60 + 10, "fdf", false);
		m->image = mlx_new_image(m->window, 1400, 1000);
		p_background(*m);
		p_walls(*m);
		mlx_key_hook(m->window, &keyhook, m);
		mlx_loop(m->window);
		//ft_draw(*m);
		//mlx_image_to_window(m->window, m->image, 0, 0);
	}
	return (EXIT_SUCCESS);
}
