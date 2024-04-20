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

static void	draw_iter(t_fractal *fract)
{
	char	*str;

	str = ft_itoa(fract->max_iter);
	mlx_string_put(fract->mlx, fract->win, 20, 20, WHITE, "Max Iterations: ");
	mlx_string_put(fract->mlx, fract->win, 120, 20, WHITE, str);
	free(str);
}

void	draw_infos(t_fractal *fract)
{
	draw_iter(fract);
	mlx_string_put(fract->mlx, fract->win, 20, 40, WHITE, "Commands:");
	mlx_string_put(fract->mlx, fract->win, 20, 60, WHITE, "Exit: ESC");
	mlx_string_put(fract->mlx, fract->win, 20, 80, WHITE, "Zoom: + -");
	mlx_string_put(fract->mlx, fract->win, 20, 100, WHITE, "Move: Arrows");
	mlx_string_put(fract->mlx, fract->win, 20, 120, WHITE, "Colors: W Q");
	mlx_string_put(fract->mlx, fract->win, 20, 140, WHITE,
		"Iterations: +A -S");
	mlx_string_put(fract->mlx, fract->win, 20, 160, WHITE, "Reset: R");
	if (fract->flag == 2)
	{
		mlx_string_put(fract->mlx, fract->win, 20, 200, WHITE,
			"Randomize Julia: J");
		mlx_string_put(fract->mlx, fract->win, 20, 220, WHITE,
			"Increase\\Decrease C: K L");
	}
}

void	draw_fractal(t_fractal *frac)
{
	if (frac->flag == 1)
		draw_mandelbrot(frac);
	else if (frac->flag == 2)
		draw_julia(frac);
}

void	put_pixel(t_fractal *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
