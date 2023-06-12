/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/12 15:37:10 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <memory.h>
#include "fdf.h"

void	close_hook(void *param)
{
	t_map	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->window, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->window);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*mlx;

	mlx = param;
	if (ydelta > 0)
	{
		if (mlx->persv->a <= 1.8f)
			mlx->persv->a += 0.01f;
		if (mlx->persv->b <= 1.8f)
			mlx->persv->b += 0.01f;
	}
	else if (ydelta < 0)
	{
		if (mlx->persv->a > 0.0f)
			mlx->persv->a -= 0.03f;
		if (mlx->persv->b > 0.0f)
			mlx->persv->b -= 0.03f;
	}
	if (xdelta < 0)
		mlx->xoff -= 0.25f;
	else if (xdelta > 0)
		mlx->xoff += 0.25f;
	mlx_delete_image(mlx->window, mlx->image);
	mlx->image = mlx_new_image(mlx->window, 1400, 1000);
	ft_draw(*mlx);
	mlx_image_to_window(mlx->window, mlx->image, 0, 0);
}

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
void	p_player(t_map m, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./src/test1.png");
	m.image = mlx_texture_to_image(m.window, texture);
	mlx_resize_image(m.image, m.image->width * 2.2, m.image->height * 2.2);
	mlx_image_to_window(m.window, m.image, x, y);
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
				p_player(m, x * 60, y * 60);
			if (m.map[y][x].z == 'C')
				p_collect(m, x * 60, y * 60);
			if (m.map[y][x].z == 'E')
				p_end(m, x * 60, y * 60);
			x++;
		}
		y++;
	}
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx->window, MLX_KEY_L))
		printf("up");
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
		mlx_key_hook(m->window, &my_keyhook, &m);
		mlx_loop(m->window);
		//ft_draw(*m);
		//mlx_image_to_window(m->window, m->image, 0, 0);
		/*
		mlx_scroll_hook(m->window, &my_scrollhook, m);
		*/
	}
	return (EXIT_SUCCESS);
}
