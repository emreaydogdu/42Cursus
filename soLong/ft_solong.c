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

void	p_img(t_map m, int y, char* path, char* path2, char* path3)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;
    int	x;

    x = 0;
    while (x < m.width)
    {
        texture = mlx_load_png(path2);
        if (x == 0)
            texture = mlx_load_png(path);
        else if (x == m.width - 1)
            texture = mlx_load_png(path3);
        img = mlx_texture_to_image(m.window, texture);
        mlx_resize_image(img, img->width * 2, img->height * 2);
        mlx_image_to_window(m.window, img, x * 32, y * 32);
        x++;
    }
}

void	p_wall(t_map m, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

    if (x % 2 == 0 && y % 2 == 0)
	    texture = mlx_load_png("./src/tile08.png");
    else if (x % 2 == 0 && y % 2 == 1)
	    texture = mlx_load_png("./src/tile010.png");
    else if (x % 2 == 1 && y % 2 == 1)
	    texture = mlx_load_png("./src/tile11.png");
    else
        texture = mlx_load_png("./src/tile09.png");
	img = mlx_texture_to_image(m.window, texture);
	mlx_resize_image(img, img->width * 2, img->height * 2);
	mlx_image_to_window(m.window, img, x * 32, y * 32);
}
void	p_collect(t_map m, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./src/collect.png");
	img = mlx_texture_to_image(m.window, texture);
	mlx_resize_image(img, img->width * 2, img->height * 2);
	mlx_image_to_window(m.window, img, x * 32, y * 32);
}
void	p_player(t_map *m, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./src/p2.png");
	if (m->player->enabled == 1)
		mlx_delete_image(m->window, m->player);
	m->player = mlx_texture_to_image(m->window, texture);
	mlx_resize_image(m->player, m->player->width * 2, m->player->height * 2);
	mlx_image_to_window(m->window, m->player, x * 32, y * 32);
}
void	p_end(t_map m, int x, int y)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./src/end1.png");
	img = mlx_texture_to_image(m.window, texture);
    mlx_resize_image(img, img->width * 2, img->height * 2);
    mlx_image_to_window(m.window, img, x * 32, y * 32);
    printf("%d:%d", x, y);
}
void	p_walls(t_map m)
{
	int	x;
	int	y;

	y = 1;
	while (y < m.height - 1)
	{
		x = 1;
		while (x < m.width - 1)
		{
            if (m.map[y][x] == '1')
                p_wall(m, x, y);
            if (m.map[y][x] == 'C')
                p_collect(m, x, y);
            if (m.map[y][x] == 'E')
                p_end(m, x, y);
            if (m.map[y][x] == 'P')
                p_player(&m, x, y);
			x++;
		}
		y++;
	}
}

void	p_background(t_map m)
{
	int	y;

	y = 0;
	while (y < m.height)
	{
        if (y == 0)
            p_img(m, y, "./src/tile000.png", "./src/tile001.png", "./src/tile002.png");
        else if (y == m.height - 1)
            p_img(m, y, "./src/tile022.png", "./src/tile023.png", "./src/tile024.png");
        else
            p_img(m, y, "./src/tile011.png", "./src/tile012.png", "./src/tile013.png");

        if (y == 0)
            p_img(m, y, "./src/tile01.png", "./src/tile02.png", "./src/tile03.png");
        else if (y == m.height - 1)
            p_img(m, y, "./src/tile05.png", "./src/tile02.png", "./src/tile06.png");
        else
            p_img(m, y, "./src/tile04.png", "./src/tile012.png", "./src/tile04.png");
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
		//ft_print_map(*m); // optional
		m->window = mlx_init(m->width * 32, m->height * 32, "fdf", false);
		m->image = mlx_new_image(m->window, 0, 0);
		p_background(*m);
		p_walls(*m);
		//mlx_key_hook(m->window, &keyhook, m);
		mlx_loop(m->window);
		//ft_draw(*m);
		//mlx_image_to_window(m->window, m->image, 0, 0);
	}
	return (EXIT_SUCCESS);
}
