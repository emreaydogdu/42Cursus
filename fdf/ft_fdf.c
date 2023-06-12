/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/12 13:06:43 by emaydogd         ###   ########.fr       */
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


int	main(int argc, char **argv)
{
	t_map		*m;

	m = malloc(sizeof(t_map));
	if (argc == 2)
	{
		ft_parse_map(argv[1], m);
		ft_print_map(*m);
		m->window = mlx_init(1400, 1000, "fdf", false);
		m->image = mlx_new_image(m->window, 1400, 1000);
		ft_draw(*m);
		mlx_image_to_window(m->window, m->image, 0, 0);
		/*
		mlx_scroll_hook(m->window, &my_scrollhook, m);
		mlx_key_hook(m->window, &my_keyhook, m);
		*/
		mlx_loop(m->window);
	}
	return (EXIT_SUCCESS);
}
