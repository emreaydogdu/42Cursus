/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:09:11 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:16:27 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

static void	calculate_mandelbrot(t_fractal *fract)
{
	int		i;
	double	x_tmp;

	i = 0;
	fract->flag = 1;
	fract->z_x = 0.0;
	fract->z_y = 0.0;
	fract->c_x = (fract->x / fract->zoom) + fract->offset_x;
	fract->c_y = (fract->y / fract->zoom) + fract->offset_y;
	while (++i < fract->max_iter && (fract->z_x * fract->z_x + \
		fract->z_y * fract->z_y) < 4)
	{
		x_tmp = fract->z_x * fract->z_x - fract->z_y * fract->z_y + fract->c_x;
		fract->z_y = 2.0 * fract->z_x * fract->z_y + fract->c_y;
		fract->z_x = x_tmp;
	}
	if (i == fract->max_iter)
		put_pixel(fract, fract->x, fract->y, 0x000000);
	else
		put_pixel(fract, fract->x, fract->y, (i * fract->color));
}

void	*draw_mandelbrot(t_fractal	*fract)
{
	fract->x = -1;
	while (++fract->x < WIDTH)
	{
		fract->y = -1;
		while (++fract->y < HEIGHT)
			calculate_mandelbrot(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	draw_infos(fract);
	return (NULL);
}
