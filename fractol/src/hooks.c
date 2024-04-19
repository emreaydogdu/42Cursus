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

int	key_hook(int keycode, t_fractal *fractal)
{
	if (keycode == ESC)
		killall_free(fractal);
	else if (keycode == LEFT)
		fractal->offset_x += 42 / fractal->zoom;
	else if (keycode == RIGHT)
		fractal->offset_x -= 42 / fractal->zoom;
	else if (keycode == UP)
		fractal->offset_y += 42 / fractal->zoom;
	else if (keycode == DOWN)
		fractal->offset_y -= 42 / fractal->zoom;
	else if (keycode == PLUS)
		fractal->zoom *= 1.1;
	else if (keycode == MINUS)
		fractal->zoom /= 1.1;
	else if (keycode == SPACE)
		fractal->max_iter += 10;
	if (keycode == BACKSPACE)
		fractal->max_iter -= 10;
	key_hook3(keycode, fractal);
	draw_fractal(fractal);
	return (0);
}

void	key_hook3(int keycode, t_fractal *fractal)
{
	if (keycode == R)
	{
		fractal->color += (255 * 255 * 255) / 50;
		if (fractal->color > 0xFFFFFF)
			fractal->color = BASE_COLOR;
	}
	else if (keycode == F)
	{
		fractal->color -= (255 * 255 * 255) / 50;
		if (fractal->color < 0x000000)
			fractal->color = BASE_COLOR;
	}
	key_hook5(keycode, fractal);
}

void	key_hook5(int keycode, t_fractal *fractal)
{
	if (keycode == ONE && fractal->flag == 2)
		reset_julia(fractal);
	else if (keycode == ONE)
	{
		fractal->color = BASE_COLOR;
		if (fractal->flag == 3)
			fractal->max_iter = 30;
		else
			fractal->max_iter = 100;
		fractal->max_iter = 100;
		fractal->zoom = 300;
		fractal->offset_x = -WIDTH / fractal->zoom / 2;
		fractal->offset_y = -HEIGHT / fractal->zoom / 2;
		ft_printf("Reset all!\n");
	}
	else if (fractal->flag == 2)
		julia_hook(keycode, fractal);
}

int	mouse_hook(int button, int x, int y, t_fractal *frac)
{
	if (button == LEFT_CLICK)
	{
		printf("%f : %f - %f\n", (-x / frac->zoom) - (-WIDTH / frac->zoom / 2), y / frac->zoom, (-WIDTH / frac->zoom / 2));

		frac->zoom *= 1.1f;
		frac->offset_x = -WIDTH / frac->zoom / 2;
		frac->offset_y = -HEIGHT / frac->zoom / 2;
		frac->offset_x -= (-x / frac->zoom) - (-WIDTH / frac->zoom / 2);
		frac->offset_y -= (-y / frac->zoom) - (-HEIGHT / frac->zoom / 2);
		printf("%f : %f\n", frac->offset_x, frac->offset_y);

	}
	else if (button == RIGHT_CLICK)
	{
		frac->zoom /= 1.1f;
		//frac->offset_x += 1 / frac->zoom;
		//frac->offset_y += 1;
	}
	else if (button == WHEEL_UP)
	{
		frac->zoom *= 1.1f;
		frac->offset_x -= ((WIDTH / 2) - x) / frac->zoom;
		frac->offset_y -= ((HEIGHT / 2) - y) / frac->zoom;
	}
	else if (button == WHEEL_DOWN)
	{
		frac->zoom /= 1.1f;
		frac->offset_x += (x - (WIDTH / 2)) / frac->zoom;
		frac->offset_y += (y - (HEIGHT / 2)) / frac->zoom;
	}
	ft_printf("button : %d\n", button);
	draw_fractal(frac);
	return (0);
}
