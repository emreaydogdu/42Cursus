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
#include "fdf.h"

void	p_player(t_map *m, int x, int y)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./src/p2.png");
	if (m->player->enabled == 1)
		mlx_delete_image(m->window, m->player);
	m->player = mlx_texture_to_image(m->window, texture);
	mlx_resize_image(m->player, m->player->width * 2, m->player->height * 2);
	mlx_image_to_window(m->window, m->player, x * 32, y * 32);
    //mlx_key_hook(m->window, &keyhook, m);
}

void	p_playerfirst(t_map m)
{
	int	x;
	int	y;

	y = 1;
	while (y < m.height - 1)
	{
		x = 1;
		while (x < m.width - 1)
		{
            if (m.map[y][x] == 'P'){
                p_player(&m, x, y);
                return;
            }
			x++;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	t_map		*m;

	m = malloc(sizeof(t_map));
	if (argc == 2)
	{
		ft_parse_map(argv[1], m);
		m->window = mlx_init(m->width * 32 + 64, m->height * 32 + 64, "fdf", false);

        draw_water(*m);
        draw_land(*m);
        draw_obstacle(*m);
        draw_end(*m);
        draw_collect(*m);
        //p_playerfirst(*m);
        mlx_key_hook(m->window, &keyhook, &m);

        mlx_loop(m->window);
	}
	return (EXIT_SUCCESS);
}
