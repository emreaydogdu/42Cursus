/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:06:51 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:14:48 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	draw_fractal(t_fractal *frac)
{
	if (frac->flag == 1)
		draw_mandelbrot(frac);
	else if (frac->flag == 2)
		draw_julia(frac);
}

void	my_mlx_pixel_put(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_menu(t_fractal *fractal)
{
	char	*str;

	str = ft_itoa(fractal->max_iter);
	mlx_string_put(fractal->mlx, fractal->win, 20, 20, 0x00FFFFFF,
		"Max Iterations: ");
	mlx_string_put(fractal->mlx, fractal->win, 120, 20, 0x00FFFFFF, str);
	free(str);
}

void	draw_commands_and_infos(t_fractal *fractal)
{
	draw_menu(fractal);
	mlx_string_put(fractal->mlx, fractal->win, 20, 40, 0x00FFFFFF, "Commands:");
	mlx_string_put(fractal->mlx, fractal->win, 20, 60, 0x00FFFFFF,
		"Exit: ESC");
	mlx_string_put(fractal->mlx, fractal->win, 20, 80, 0x00FFFFFF, "Zoom: + -");
	mlx_string_put(fractal->mlx, fractal->win, 20, 100, 0x00FFFFFF,
		"Move: Arrows");
	mlx_string_put(fractal->mlx, fractal->win, 20, 120, 0x00FFFFFF,
		"Change Colors: r f t");
	mlx_string_put(fractal->mlx, fractal->win, 20, 140, 0x00FFFFFF,
		"Color Shift Step: c v b");
	mlx_string_put(fractal->mlx, fractal->win, 20, 160, 0x00FFFFFF,
		"Increase Iterations: space");
	mlx_string_put(fractal->mlx, fractal->win, 20, 180, 0x00FFFFFF,
		"Decrease Iterations: backspace");
	mlx_string_put(fractal->mlx, fractal->win, 20, 200, 0x00FFFFFF, "Reset: 1");
	if (fractal->flag == 2)
	{
		mlx_string_put(fractal->mlx, fractal->win, 20, 220, 0x00FFFFFF,
			"Randomize Julia: j");
		mlx_string_put(fractal->mlx, fractal->win, 20, 240, 0x00FFFFFF,
			"Increase\\Decrease Cs: k l");
	}
}
