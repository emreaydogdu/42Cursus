/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:43:31 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/18 19:34:38 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	ft_draw_info(t_map *m)
{
	int32_t	size;

	if (!m->menu->bg)
	{
		m->menu->bg = mlx_new_image(m->window, 256, 1000);
		size = m->menu->bg->width * m->menu->bg->height * sizeof(uint32_t);
		memset(m->menu->bg->pixels, MENU_BACKGROUND, size);
		mlx_image_to_window(m->window, m->menu->bg, 0, 0);
		mlx_put_string(m->window, "FDF - Informations", 10, 10);
		mlx_put_string(m->window, "// CONTROLS //", 10, 50);
		mlx_put_string(m->window, "[ ESC ]          close", 10, 80);
		mlx_put_string(m->window, "[ Arrows/Mouse ] move", 10, 110);
		mlx_put_string(m->window, "[ Mouse Scroll ] zoom", 10, 140);
		mlx_put_string(m->window, "[ Y/X/C ] projection", 10, 170);
		mlx_put_string(m->window, "// VALUES //", 10, 270);
	}
}

void	ft_draw_menu(t_map *m)
{
	char	s[100];

	ft_draw_info(m);
	if (m->menu->bg)
	{
		mlx_delete_image(m->window, m->menu->xoff);
		mlx_delete_image(m->window, m->menu->yoff);
		mlx_delete_image(m->window, m->menu->zoff);
		mlx_delete_image(m->window, m->menu->yaw);
		mlx_delete_image(m->window, m->menu->pitch);
		mlx_delete_image(m->window, m->menu->roll);
		mlx_delete_image(m->window, m->menu->zoom);
	}
	sprintf(s, "X-Offset:	%f", m->xoff);
	m->menu->xoff = mlx_put_string(m->window, s, 10, 300);
	sprintf(s, "Y-Offset:	%f", m->yoff);
	m->menu->yoff = mlx_put_string(m->window, s, 10, 330);
	sprintf(s, "Z-Offset:	%f", m->zoff);
	m->menu->zoff = mlx_put_string(m->window, s, 10, 360);
	sprintf(s, "X-Axis:			%f", m->persv.a);
	m->menu->yaw = mlx_put_string(m->window, s, 10, 390);
	sprintf(s, "Y-Axis:			%f", m->persv.b);
	m->menu->pitch = mlx_put_string(m->window, s, 10, 420);
	sprintf(s, "Z-Axis:			%f", m->persv.c);
	m->menu->roll = mlx_put_string(m->window, s, 10, 450);
	sprintf(s, "zoom:	%d", (int)m->zoom);
	m->menu->zoom = mlx_put_string(m->window, s, 10, 480);
}
