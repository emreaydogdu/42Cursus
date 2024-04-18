/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:09:19 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:11:24 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

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
