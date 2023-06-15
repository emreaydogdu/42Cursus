/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:15:06 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/15 16:17:59 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	keyhook(mlx_key_data_t key, void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->window, MLX_KEY_R))
	{
		m->yoff = 0;
		m->xoff = 0;
		m->zoom = 40;
		m->persv->a = 0;
		m->persv->b = 0;
		m->persv->c = 0;
	}
	if (mlx_is_key_down(m->window, MLX_KEY_RIGHT))
		m->xoff += 10;
	if (mlx_is_key_down(m->window, MLX_KEY_LEFT))
		m->xoff -= 10;
	if (mlx_is_key_down(m->window, MLX_KEY_UP))
		m->yoff -= 10;
	if (mlx_is_key_down(m->window, MLX_KEY_DOWN))
		m->yoff += 10;
	ft_draw_image(m);
	ft_draw_menu(m);
}

void	close_hook(void *param)
{
	t_map	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->window, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->window);
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*m;

	m = param;
	if (ydelta > 0)
		m->persv->a += 0.01f;
	else if (ydelta < 0)
		m->persv->a -= 0.01f;
	if (xdelta < 0)
		m->persv->b -= 0.01f;
	else if (xdelta > 0)
		m->persv->b += 0.01f;
	ft_draw_image(m);
	ft_draw_menu(m);
}

void	loophook(void *param)
{
	t_map	*m;

	m = param;
	if (m->menu->mouse_pos)
		mlx_delete_image(m->window, m->menu->mouse_pos);
	m->menu->mouse_pos = mlx_put_string(m->window, "Hello", 0, 0);
}

void	mousehook(mouse_key_t k, action_t a, modifier_key_t mk, void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_mouse_down(m->window, MLX_MOUSE_BUTTON_LEFT))
		printf("%f:%f\n", 4.0, 5.0);
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
		printf("m: %d	m: %d\n", (int)x - m->pmx, (int)y - m->pmy);
	}
	if (mlx_is_mouse_down(m->window, MLX_MOUSE_BUTTON_MIDDLE))
	{
		m->persv->b += (x - m->pmx)/1000;
		m->persv->a += (y - m->pmy)/1000;
	}
	ft_draw_image(m);
	ft_draw_menu(m);
}
