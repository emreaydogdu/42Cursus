/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/11 22:43:06 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	close_hook(void *param)
{
	t_map	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->window, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->window);
}
/*
void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*mlx;

	mlx = param;
	if (ydelta > 0)
	{
		mlx->yoff = 0.001f;
		printf("UP! %f", mlx->yoff);
	}
	else if (ydelta < 0)
		printf("DOWN!");

	// Can also detect a mousewheel that goes along the X (e.g: MX Master 3)
	if (xdelta < 0)
		puts("Sliiiide to the left!");
	else if (xdelta > 0)
		puts("Sliiiide to the right!");

	mlx_delete_image(mlx->window, mlx->image);
	mlx->image = mlx_new_image(mlx->window, 1400, 1000);
	ft_draw(*mlx);
	mlx_image_to_window(mlx->window, mlx->image, 0, 0);
}
 */


int	main(int argc, char **argv)
{
	t_map	m;

	//m = malloc(sizeof(t_map));
	if (argc == 2)
	{
		ft_parse_map(argv[1], &m);
		m.window = mlx_init(1400, 1000, "fdf", false);
		m.image = mlx_new_image(m.window, 1400, 1000);
		ft_draw(m);
		mlx_image_to_window(m.window, m.image, 0, 0);
		//ft_draw_menu(m);
		mlx_key_hook(m.window, &my_keyhook, &m);
		//mlx_loop_hook(m.window, &close_hook, &m);
		//mlx_scroll_hook(m.window, &my_scrollhook, &m);
		mlx_loop(m.window);
	}
	return (EXIT_SUCCESS);
}
