/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:07:51 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:12:07 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	x_tmp;

	i = 0;
	fractal->z_x = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->z_y = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iter && (fractal->z_x * fractal->z_x + fractal->z_y * fractal->z_y) < 4)
	{
		x_tmp = fractal->z_x;
		fractal->z_x = fractal->z_x * fractal->z_x - fractal->z_y * fractal->z_y + fractal->c_x;
		fractal->z_y = 2.0 * x_tmp * fractal->z_y + fractal->c_y;
	}
	if (i == fractal->max_iter)
		put_pixel(fractal, fractal->x, fractal->y, 0x000000);
	else
		put_pixel(fractal, fractal->x, fractal->y, (i * fractal->color));
}

void	*draw_julia(t_fractal *fractal)
{
	fractal->x = -1;
	while (++fractal->x < WIDTH)
	{
		fractal->y = -1;
		while (++fractal->y < HEIGHT)
			calculate_julia(fractal);
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	draw_infos(fractal);
	return (NULL);
}

int	julia_hook(int keycode, t_fractal *fractal)
{
	if (keycode == J)
		random_double(fractal);
	else if (keycode == K)
	{
		fractal->c_x += C_STEP;
		fractal->c_y += C_STEP;
	}
	else if (keycode == L)
	{
		fractal->c_x -= C_STEP;
		fractal->c_y -= C_STEP;
	}
	return (0);
}

void	reset_julia(t_fractal *fractal)
{
	fractal->c_x = -0.8;
	fractal->c_y = 0.2;
	fractal->color = BASE_COLOR;
	fractal->max_iter = 100;
	fractal->zoom = 300;
	fractal->offset_x = -WIDTH / fractal->zoom / 2;
	fractal->offset_y = -HEIGHT / fractal->zoom / 2;
}
