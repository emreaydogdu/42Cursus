/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/14 23:21:24 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	hook_up_h(t_map *m)
{
	if (mlx_is_key_down(m->window, MLX_KEY_UP))
	{
		if (m->map[m->pos.y - 1][m->pos.x] == 'C' || \
			m->map[m->pos.y - 1][m->pos.x] == '0')
		{
			m->pos.y -= 1;
			m->player->instances[0].y -= 32;
			find_collectibles(m->pos.x, m->pos.y, m);
		}
	}
}

void	hook_down_h(t_map *m)
{
	if (mlx_is_key_down(m->window, MLX_KEY_DOWN))
	{
		if (m->map[m->pos.y + 1][m->pos.x] == 'C' || \
			m->map[m->pos.y + 1][m->pos.x] == '0')
		{
			m->pos.y += 1;
			m->player->instances[0].y += 32;
			find_collectibles(m->pos.x, m->pos.y, m);
		}
	}
}

void	hook_left_h(t_map *m)
{
	if (mlx_is_key_down(m->window, MLX_KEY_LEFT))
	{
		if (m->map[m->pos.y][m->pos.x - 1] == 'C' || \
			m->map[m->pos.y][m->pos.x - 1] == '0')
		{
			m->pos.x -= 1;
			m->player->instances[0].x -= 32;
			find_collectibles(m->pos.x, m->pos.y, m);
		}
	}
}

void	hook_right_h(t_map *m)
{
	if (mlx_is_key_down(m->window, MLX_KEY_RIGHT))
	{
		if (m->map[m->pos.y][m->pos.x + 1] == 'C' || \
			m->map[m->pos.y][m->pos.x + 1] == '0')
		{
			m->pos.x += 1;
			m->player->instances[0].x += 32;
			find_collectibles(m->pos.x, m->pos.y, m);
		}
	}
}
