/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:15:06 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/17 13:56:46 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	keyhook(mlx_key_data_t key, void *param)
{
	t_map	*m;

	m = param;
	if (mlx_is_key_down(m->window, (MLX_KEY_Q)))
		mlx_close_window(m->window);
	if (mlx_is_key_down(m->window, MLX_KEY_A))
		m->persv->a += 0.1f;
	if (mlx_is_key_down(m->window, MLX_KEY_S))
		m->persv->a -= 0.1f;
	if (mlx_is_key_down(m->window, MLX_KEY_D))
		m->persv->b += 0.1f;
	if (mlx_is_key_down(m->window, MLX_KEY_F))
		m->persv->b -= 0.1f;
	if (mlx_is_key_down(m->window, MLX_KEY_G))
		m->persv->c += 0.1f;
	if (mlx_is_key_down(m->window, MLX_KEY_H))
		m->persv->c -= 0.1f;
	if (mlx_is_key_down(m->window, MLX_KEY_R))
	{
		m->yoff = 0;
		m->xoff = 0;
		m->zoom = 40;
		free(m->persv);
		m->persv = ft_persv(m->projection);
	}
	if (mlx_is_key_down(m->window, MLX_KEY_RIGHT))
		m->xoff += 5;
	if (mlx_is_key_down(m->window, MLX_KEY_LEFT))
		m->xoff -= 5;
	if (mlx_is_key_down(m->window, MLX_KEY_UP))
		m->yoff -= 5;
	if (mlx_is_key_down(m->window, MLX_KEY_DOWN))
		m->yoff += 5;
	if (mlx_is_key_down(m->window, MLX_KEY_Z))
	{
		free(m->persv);
		m->projection = 0;
		m->persv = ft_persv(m->projection);
	}
	if (mlx_is_key_down(m->window, MLX_KEY_X))
	{
		free(m->persv);
		m->projection = 1;
		m->persv = ft_persv(m->projection);
	}
	if (mlx_is_key_down(m->window, MLX_KEY_C))
	{
		free(m->persv);
		m->projection = 2;
		m->persv = ft_persv(m->projection);
	}
	ft_draw_image(m);
	ft_draw_menu(m);
}

void	closehook(void *param)
{
	t_map	*fdf;

	fdf = param;
	puts("Closed Window");
}

void	scrollhook(double xdelta, double ydelta, void *param)
{
	t_map	*m;

	m = param;
	if (ydelta > 0)
		m->zoom += 1.0f;
	else if (ydelta < 0 && m->zoom > 1)
		m->zoom -= 1.0f;
	ft_draw_image(m);
	ft_draw_menu(m);
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
	}
	if (mlx_is_mouse_down(m->window, MLX_MOUSE_BUTTON_MIDDLE))
	{
		m->persv->a -= (y - m->pmy)/1000;
		m->persv->b += (x - m->pmx)/1000;
	}
	ft_draw_image(m);
	ft_draw_menu(m);
}
