/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:25:52 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:05 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		killall_free(fractal);
	else if (keycode == LEFT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (keycode == RIGHT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (keycode == UP)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (keycode == DOWN)
		fractal->offset_y += 42 / fractal->zoom;
	else if (keycode == PLUS)
		fractal->zoom *= 1.1;
	else if (keycode == MINUS)
		fractal->zoom /= 1.1;
	else if (keycode == SPACE)
		fractal->max_iter += 10;
	key_hook3(keycode, fractal);
	draw_fractal(fractal);
	return (0);
}

void	key_hook3(int keycode, t_fractal *fractal)
{
	if (keycode == BACKSPACE)
		fractal->max_iter -= 10;
	else if (keycode == R)
	{
		fractal->color += fractal->color_shift_step;
		if (fractal->color > fractal->color_shift_max)
			fractal->color = BASE_COLOR;
		ft_printf("Increased color shift!\n");
	}
	else if (keycode == F)
	{
		fractal->color -= fractal->color_shift_step;
		if (fractal->color < fractal->color_shift_min)
			fractal->color = BASE_COLOR;
		ft_printf("Decreased color shift!\n");
	}
	key_hook4(keycode, fractal);
}

void	key_hook4(int keycode, t_fractal *fractal)
{
	if (keycode == T)
	{
		fractal->color = BASE_COLOR;
		ft_printf("Reset color shift!\n");
	}
	else if (keycode == C)
	{
		fractal->color_shift_step += 1;
		ft_printf("Increased color shift step!\n");
	}
	else if (keycode == V)
	{
		fractal->color_shift_step -= 1;
		ft_printf("Decreased color shift step!\n");
	}
	else if (keycode == B)
	{
		fractal->color_shift_step = (255 * 255 * 255) / 100;
		ft_printf("Reset color shift step!\n");
	}
	key_hook5(keycode, fractal);
}

void	key_hook5(int keycode, t_fractal *fractal)
{
	if (keycode == ONE && fractal->flag == 2)
		reset_julia(fractal);
	else if (keycode == ONE)
	{
		fractal->color_shift_step = (255 * 255 * 255) / 100;
		fractal->color = BASE_COLOR;
		if (fractal->flag == 3)
			fractal->max_iter = 30;
		else
			fractal->max_iter = 100;
		fractal->max_iter = 100;
		fractal->zoom = 300;
		fractal->offset_x = -2.1;
		fractal->offset_y = -1.21;
		ft_printf("Reset all!\n");
	}
	else if (fractal->flag == 2)
		julia_hook(keycode, fractal);
}
