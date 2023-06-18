/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:43:31 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/15 14:31:35 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <memory.h>

// 'Encodes' four individual bytes into an int.
static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_draw_menu(t_map *m)
{
	char	s[100];

	if (!m->menu->bg)
	{
		m->menu->bg = mlx_new_image(m->window, 256, 1000);
		memset(m->menu->bg->pixels, 0x70FFFF70, m->menu->bg->width * m->menu->bg->height * sizeof(int32_t));
		mlx_image_to_window(m->window, m->menu->bg, 0, 0);
		mlx_put_string(m->window, "FDF - Informations", 10, 10);
		mlx_put_string(m->window, "[ STATUS ]", 10, 50);
	}
	if (m->menu->xoff)
	{
		mlx_delete_image(m->window, m->menu->xoff);
		mlx_delete_image(m->window, m->menu->yoff);
		mlx_delete_image(m->window, m->menu->yaw);
		mlx_delete_image(m->window, m->menu->pitch);
		mlx_delete_image(m->window, m->menu->roll);
		mlx_delete_image(m->window, m->menu->zoom);
	}
	sprintf(s, "x-Offset:	%f", m->xoff);
	m->menu->xoff = mlx_put_string(m->window, s, 10, 80);
	sprintf(s, "y-Offset:	%f", m->yoff);
	m->menu->yoff = mlx_put_string(m->window, s, 10, 110);
	sprintf(s, "yaw:	%f", m->persv.a);
	m->menu->yaw = mlx_put_string(m->window, s, 10, 140);
	sprintf(s, "pitch:	%f", m->persv.b);
	m->menu->pitch = mlx_put_string(m->window, s, 10, 170);
	sprintf(s, "roll:	%f", m->persv.c);
	m->menu->roll = mlx_put_string(m->window, s, 10, 200);
	sprintf(s, "zoom:	%d", (int)m->zoom);
	m->menu->zoom = mlx_put_string(m->window, s, 10, 230);
}
