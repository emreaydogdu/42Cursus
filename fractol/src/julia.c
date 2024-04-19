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

static void	calculate_julia(t_fractal *fract)
{
	int		i;
	double	x_tmp;

	i = 0;
	fract->z_x = (fract->x / fract->zoom) + fract->offset_x;
	fract->z_y = (fract->y / fract->zoom) + fract->offset_y;
	while (++i < fract->max_iter && (fract->z_x * \
		fract->z_x + fract->z_y * fract->z_y) < 4)
	{
		x_tmp = fract->z_x;
		fract->z_x = fract->z_x * fract->z_x - \
			fract->z_y * fract->z_y + fract->c_x;
		fract->z_y = 2.0 * x_tmp * fract->z_y + fract->c_y;
	}
	if (i == fract->max_iter)
		put_pixel(fract, fract->x, fract->y, 0x000000);
	else
		put_pixel(fract, fract->x, fract->y, (i * fract->color));
}

void	*draw_julia(t_fractal *fract)
{
	fract->x = -1;
	while (++fract->x < WIDTH)
	{
		fract->y = -1;
		while (++fract->y < HEIGHT)
			calculate_julia(fract);
	}
	mlx_put_image_to_window(fract->mlx, fract->win, fract->img, 0, 0);
	draw_infos(fract);
	return (NULL);
}

int	julia_hook(int keycode, t_fractal *fract)
{
	if (keycode == J)
		random_double(fract);
	else if (keycode == K)
	{
		fract->c_x += C_STEP;
		fract->c_y += C_STEP;
	}
	else if (keycode == L)
	{
		fract->c_x -= C_STEP;
		fract->c_y -= C_STEP;
	}
	return (0);
}

void	reset_julia(t_fractal *fract)
{
	fract->c_x = -0.8;
	fract->c_y = 0.2;
	fract->color = BASE_COLOR;
	fract->max_iter = 100;
	fract->zoom = 300;
	fract->offset_x = -WIDTH / fract->zoom / 2;
	fract->offset_y = -HEIGHT / fract->zoom / 2;
}
