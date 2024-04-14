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

int	main(int argc, char **argv)
{
	t_map		*m;

	if (argc != 2)
		ft_error(ERR_ARGS, NULL);
	m = malloc(sizeof(t_map));
	if (!m)
		exit(EXIT_FAILURE);
	ft_map_check(argv[1], m);
	m->window = mlx_init(m->width * 32 + 64, m->height * 32 + 64, \
		"so_long", false);
	draw_water(m);
	draw_land(m);
	draw_obstacle(m);
	draw_end(m);
	draw_collect(m);
	draw_player(m);
	mlx_key_hook(m->window, &keyhook, m);
	mlx_loop(m->window);
	mlx_terminate(m->window);
	return (EXIT_SUCCESS);
}