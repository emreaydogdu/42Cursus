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

void	calculate_julia(t_fractal *fractal)
{
	int		i;
	double	x_tmp;

	i = 0;
	fractal->flag = 2;
	fractal->z_x = (fractal->x / fractal->zoom) + fractal->offset_x;
	fractal->z_y = (fractal->y / fractal->zoom) + fractal->offset_y;
	while (++i < fractal->max_iter && (fractal->z_x
			* fractal->z_x + fractal->z_y * fractal->z_y) < 4)
	{
		x_tmp = fractal->z_x;
		fractal->z_x = fractal->z_x * fractal->z_x - fractal->z_y
			* fractal->z_y + fractal->c_x - 0.8;
		fractal->z_y = 2.0 * x_tmp * fractal->z_y + fractal->c_y;
	}
	if (i == fractal->max_iter)
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, 0x000000);
	else
		my_mlx_pixel_put(fractal, fractal->x, fractal->y, (i * fractal->color));
}

void	*draw_julia(t_fractal *fractal)
{
	fractal->x = 0;
	while (fractal->x < WIDTH)
	{
		fractal->y = 0;
		while (fractal->y < HEIGHT)
		{
			calculate_julia(fractal);
			fractal->y++;
		}
		fractal->x++;
	}
	mlx_put_image_to_window(fractal->mlx, fractal->win, fractal->img, 0, 0);
	draw_commands_and_infos(fractal);
	return (NULL);
}

int	julia_hook(int keycode, t_fractal *fractal)
{
	if (keycode == J)
	{
		random_double(fractal);
		ft_printf("Rnd Julia!\ncx: %f\tcy: %f\n", fractal->c_x, fractal->c_y);
	}
	else if (keycode == K)
	{
		fractal->c_x += C_STEP;
		fractal->c_y += C_STEP;
		ft_printf("Increased Cs!\n");
	}
	else if (keycode == L)
	{
		fractal->c_x -= C_STEP;
		fractal->c_y -= C_STEP;
		ft_printf("Decreased Cs!\n");
	}
	return (0);
}

void	reset_julia(t_fractal *fractal)
{
	fractal->c_x = 0.0;
	fractal->c_y = 0.138240;
	fractal->color_shift_step = (255 * 255 * 255) / 100;
	fractal->color = BASE_COLOR;
	fractal->max_iter = 100;
	fractal->zoom = 300;
	fractal->offset_x = -2.1;
	fractal->offset_y = -1.21;
	ft_printf("Reset Julia!\n");
}
