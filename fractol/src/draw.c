/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:25:34 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 15:24:04 by fzucconi         ###   ########.fr       */
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
	mlx_string_put(fractal->mlx, fractal->win, 650, 30, 0x00FF0000, "Menu:");
	mlx_string_put(fractal->mlx, fractal->win, 670, 50, 0x00FF0000,
		"Max Iterations: ");
	mlx_string_put(fractal->mlx, fractal->win, 670, 70, 0x00FF0000, str);
	free(str);
	//str = 0;
}

void	draw_commands_and_infos(t_fractal *fractal)
{
	draw_menu(fractal);
	mlx_string_put(fractal->mlx, fractal->win, 20, 30, 0x00FF0000, "Commands:");
	mlx_string_put(fractal->mlx, fractal->win, 40, 50, 0x00FF0000, "Zoom: + -");
	mlx_string_put(fractal->mlx, fractal->win, 40, 70, 0x00FF0000,
		"Move: Arrows");
	mlx_string_put(fractal->mlx, fractal->win, 40, 90, 0x00FF0000,
		"Change Colors: r f t");
	mlx_string_put(fractal->mlx, fractal->win, 40, 110, 0x00FF0000,
		"Color Shift Step: c v b");
	mlx_string_put(fractal->mlx, fractal->win, 40, 130, 0x00FF0000,
		"Increase Iterations: space");
	mlx_string_put(fractal->mlx, fractal->win, 40, 150, 0x00FF0000,
		"Decrease Iterations: backspace");
	mlx_string_put(fractal->mlx, fractal->win, 40, 170, 0x00FF0000, "Reset: 1");
	if (fractal->flag == 2)
	{
		mlx_string_put(fractal->mlx, fractal->win, 40, 190, 0x00FF0000,
			"Randomize Julia: j");
		mlx_string_put(fractal->mlx, fractal->win, 40, 210, 0x00FF0000,
			"Increase\\Decrease Cs: k l");
		mlx_string_put(fractal->mlx, fractal->win, 40, 230, 0x00FF0000,
			"Exit: ESC");
	}
	else
		mlx_string_put(fractal->mlx, fractal->win, 40, 190, 0x00FF0000,
			"Exit: ESC");
}
