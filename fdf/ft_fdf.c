/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/15 13:17:23 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <memory.h>
#include "fdf.h"

void	test(t_map *m, int x, int y)
{
	mlx_image_t	*img;
	img = mlx_new_image(m->window, 1144, 1000);
	memset(img->pixels, 0xFFFFFF, img->width * img->height * sizeof(int32_t));
	mlx_put_pixel(img, x, y, 0x033077);
	mlx_image_to_window(m->window, img, 256, 0);
}

int	main(int argc, char **argv)
{
	t_map		*m;

	m = malloc(sizeof(t_map));
	if (argc == 2)
	{
		ft_parse_map(argv[1], m);
		m->window = mlx_init(1400, 1000, "fdf", false);
		ft_draw_image(m);
		//test(m, 256, 600);
		ft_draw_menu(m);
		mlx_key_hook(m->window, &keyhook, m);
		mlx_scroll_hook(m->window, &scrollhook, m);
		//mlx_mouse_hook(m->window, &mousehook, m);
		mlx_cursor_hook(m->window, &cursorhook, m);
		mlx_loop(m->window);
	}
	return (EXIT_SUCCESS);
}
