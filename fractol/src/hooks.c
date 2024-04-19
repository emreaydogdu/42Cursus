/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:08:15 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:12:12 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

int	key_hook(int keycode, t_fractal *fract)
{
	if (keycode == ESC)
		killall_free(fract);
	else if (keycode == LEFT)
		fract->offset_x += 42 / fract->zoom;
	else if (keycode == RIGHT)
		fract->offset_x -= 42 / fract->zoom;
	else if (keycode == UP)
		fract->offset_y += 42 / fract->zoom;
	else if (keycode == DOWN)
		fract->offset_y -= 42 / fract->zoom;
	else if (keycode == PLUS)
		fract->zoom *= 1.1;
	else if (keycode == MINUS)
		fract->zoom /= 1.1;
	else if (keycode == SPACE)
		fract->max_iter += 10;
	if (keycode == BACKSPACE)
		fract->max_iter -= 10;
	key_hook3(keycode, fract);
	draw_fractal(fract);
	return (0);
}

void	key_hook3(int keycode, t_fractal *fract)
{
	if (keycode == R)
	{
		fract->color += (255 * 255 * 255) / 50;
		if (fract->color > 0xFFFFFF)
			fract->color = BASE_COLOR;
	}
	else if (keycode == F)
	{
		fract->color -= (255 * 255 * 255) / 50;
		if (fract->color < 0x000000)
			fract->color = BASE_COLOR;
	}
	key_hook5(keycode, fract);
}

void	key_hook5(int keycode, t_fractal *fract)
{
	if (keycode == ONE && fract->flag == 2)
		reset_julia(fract);
	else if (keycode == ONE)
	{
		fract->color = BASE_COLOR;
		if (fract->flag == 3)
			fract->max_iter = 30;
		else
			fract->max_iter = 100;
		fract->max_iter = 100;
		fract->zoom = 300;
		fract->offset_x = -WIDTH / fract->zoom / 2;
		fract->offset_y = -HEIGHT / fract->zoom / 2;
	}
	else if (fract->flag == 2)
		julia_hook(keycode, fract);
}

int	mouse_hook(int button, int x, int y, t_fractal *fract)
{
	if (button == WHEEL_UP || button == LEFT_CLICK)
	{
		fract->zoom *= 1.1f;
		fract->offset_x -= ((WIDTH / 2) - x) / fract->zoom;
		fract->offset_y -= ((HEIGHT / 2) - y) / fract->zoom;
	}
	else if (button == WHEEL_DOWN || button == RIGHT_CLICK)
	{
		fract->zoom /= 1.1f;
		fract->offset_x += (x - (WIDTH / 2)) / fract->zoom;
		fract->offset_y += (y - (HEIGHT / 2)) / fract->zoom;
	}
	draw_fractal(fract);
	return (0);
}
