/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/17 16:46:09 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	*m;

	if (argc == 2)
	{
		m = malloc(sizeof(t_map));
		ft_parse_map(argv[1], m);
		m->window = mlx_init(1400, 1000, "fdf", false);
		ft_draw_image(m);
		ft_draw_menu(m);
		mlx_key_hook(m->window, &keyhook, m);
		mlx_scroll_hook(m->window, &scrollhook, m);
		mlx_cursor_hook(m->window, &cursorhook, m);
		mlx_loop(m->window);
	}
	return (EXIT_SUCCESS);
}
