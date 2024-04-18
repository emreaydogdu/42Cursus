/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:14:02 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 13:37:21 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == WHEEL_UP || button == LEFT_CLICK)
	{
		fractal->zoom *= 1.1f;
		fractal->offset_x -= ((WIDTH / 2) - x) / fractal->zoom;
		fractal->offset_y -= ((HEIGHT / 2) - y) / fractal->zoom;
	}
	else if (button == WHEEL_DOWN || button == RIGHT_CLICK)
	{
		fractal->zoom /= 1.1f;
		fractal->offset_x += (x - (WIDTH / 2)) / fractal->zoom;
		fractal->offset_y += (y - (HEIGHT / 2)) / fractal->zoom;
	}
	ft_printf("button : %d\n", button);
	draw_fractal(fractal);
	return (0);
}
