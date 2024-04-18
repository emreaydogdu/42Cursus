/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:25:12 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 14:06:09 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	calculate_burningship(t_fractal *fractal)
{
	int		i;
	double	x_tmp;

	i = 0;
	fractal->flag = 3;
	fractal->z_x = 0.0;
	fractal->z_y = 0.0;
	fractal->c_x = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->c_y = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iter)
	{
		x_tmp = fractal->z_x * fractal->z_x - fractal->z_y
			* fractal->z_y + fractal->c_x;
		fractal->z_y = abs_double(2.0 * fractal->z_x
				* fractal->z_y) + fractal->c_y;
		fractal->z_x = x_tmp;
		if ((fractal->z_x * fractal->z_x + fractal->z_y
				* fractal->z_y) > __DBL_MAX__)
			break ;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
}

void	*draw_burningship(void *frac_void)
{
	t_fractal	*fractal;

	fractal = (t_fractal *)frac_void;
	fractal->x = 0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			calculate_burningship(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	draw_commands_and_infos(fractal);
	return (NULL);
}
