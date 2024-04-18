/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:26:01 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 17:08:55 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	calculate_mandelbrot(t_fractal *fractal)
{
	int		i;
	double	x_tmp;

	i = 0;
	fractal->flag = 1;
	fractal->z_x = 0.0;
	fractal->z_y = 0.0;
	fractal->c_x = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->c_y = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iter && (fractal->z_x
			* fractal->z_x + fractal->z_y * fractal->z_y) < 4)
	{
		x_tmp = fractal->z_x * fractal->z_x - fractal->z_y
			* fractal->z_y + fractal->c_x;
		fractal->z_y = 2.0 * fractal->z_x * fractal->z_y + fractal->c_y;
		fractal->z_x = x_tmp;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
}

void	*draw_mandelbrot(void *frac_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)frac_void;
	fractal->x = 0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			calculate_mandelbrot(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	draw_commands_and_infos(fractal);
	return (NULL);
}
