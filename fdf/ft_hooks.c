/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:15:06 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/18 20:18:39 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	ft_key_rotation(t_map *m)
{
	if (mlx_is_key_down(m->window, MLX_KEY_A))
		m->persv.a += 0.1;
	if (mlx_is_key_down(m->window, MLX_KEY_S))
		m->persv.a -= 0.1;
	if (mlx_is_key_down(m->window, MLX_KEY_D))
		m->persv.b += 0.1;
	if (mlx_is_key_down(m->window, MLX_KEY_F))
		m->persv.b -= 0.1;
	if (mlx_is_key_down(m->window, MLX_KEY_G))
		m->persv.c += 0.1;
	if (mlx_is_key_down(m->window, MLX_KEY_H))
		m->persv.c -= 0.1;
	if (mlx_is_key_down(m->window, MLX_KEY_R))
	{
		m->yoff = 0;
		m->xoff = 0;
		m->zoff = 2;
		m->zoom = 40;
		m->persv = ft_persv(m->proj);
	}
}

static void	ft_key_translation(t_map *m)
{
	if (mlx_is_key_down(m->window, MLX_KEY_RIGHT))
		m->xoff += 5;
	if (mlx_is_key_down(m->window, MLX_KEY_LEFT))
		m->xoff -= 5;
	if (mlx_is_key_down(m->window, MLX_KEY_UP))
		m->yoff -= 5;
	if (mlx_is_key_down(m->window, MLX_KEY_DOWN))
		m->yoff += 5;
	if (mlx_is_key_down(m->window, MLX_KEY_Q))
		m->zoff -= 1.0f;
	if (mlx_is_key_down(m->window, MLX_KEY_W))
		m->zoff += 1.0f;
}

void	keyhook(mlx_key_data_t key, void *param)
{
	t_map	*m;

	m = param;
	(void) key;
	ft_key_rotation(m);
	ft_key_translation(m);
	if (mlx_is_key_down(m->window, (MLX_KEY_ESCAPE)))
		mlx_close_window(m->window);
	if (mlx_is_key_down(m->window, MLX_KEY_Z))
	{
		m->proj = 0;
		m->persv = ft_persv(m->proj);
	}
	if (mlx_is_key_down(m->window, MLX_KEY_X))
	{
		m->proj = 1;
		m->persv = ft_persv(m->proj);
	}
	if (mlx_is_key_down(m->window, MLX_KEY_C))
	{
		m->proj = 2;
		m->persv = ft_persv(m->proj);
	}
	ft_draw_image(m);
	ft_draw_menu(m);
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*m;

	m = param;
	(void)xdelta;
	if (ydelta > 0)
		m->zoom += 1.0f;
	else if (ydelta < 0 && m->zoom > 1)
		m->zoom -= 1.0f;
	ft_draw_image(m);
	ft_draw_menu(m);
}

void	cursorhook(double x, double y, void *param)
{
	t_map	*m;

	m = param;
	m->pmx = m->mx;
	m->pmy = m->my;
	m->mx = x;
	m->my = y;
	if (mlx_is_mouse_down(m->window, MLX_MOUSE_BUTTON_LEFT))
	{
		m->xoff += x - m->pmx;
		m->yoff += y - m->pmy;
	}
	if (mlx_is_mouse_down(m->window, MLX_MOUSE_BUTTON_RIGHT))
	{
		m->persv.a -= (y - m->pmy) / 1000;
		m->persv.b += (x - m->pmx) / 1000;
	}
	ft_draw_image(m);
	ft_draw_menu(m);
}
