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

void	keyhook(mlx_key_data_t keydata, void *param)
{
    t_map	*m;

    m = param;
    (void) keydata;

    if (mlx_is_key_down(m->window, (MLX_KEY_A)))
    {
        m->end->enabled = false;
        m->end2->enabled = true;
    }
    if (mlx_is_key_down(m->window, (MLX_KEY_D)))
    {
        m->end->enabled = true;
        m->end2->enabled = false;
    }
    if (mlx_is_key_down(m->window, (MLX_KEY_ESCAPE)))
        mlx_close_window(m->window);
    if (mlx_is_key_down(m->window, MLX_KEY_UP))
    {
        if (m->map[m->pos.y-1][m->pos.x] == 'C' || m->map[m->pos.y-1][m->pos.x] == '0')
        {
            m->pos.y -= 1;
            m->player->instances[0].y -= 32;
        }
    }
    if (mlx_is_key_down(m->window, MLX_KEY_DOWN))
    {
        if (m->map[m->pos.y+1][m->pos.x] == 'C' || m->map[m->pos.y+1][m->pos.x] == '0')
        {
            m->pos.y += 1;
            m->player->instances[0].y += 32;
        }
    }
    if (mlx_is_key_down(m->window, MLX_KEY_RIGHT))
    {
        if (m->map[m->pos.y][m->pos.x+1] == 'C' || m->map[m->pos.y][m->pos.x+1] == '0')
        {
            m->pos.x += 1;
            m->player->instances[0].x += 32;
        }
    }
    if (mlx_is_key_down(m->window, MLX_KEY_LEFT))
    {
        if (m->map[m->pos.y][m->pos.x-1] == 'C' || m->map[m->pos.y][m->pos.x-1] == '0')
        {
            m->pos.x -= 1;
            m->player->instances[0].x -= 32;
        }
    }
    if (mlx_is_key_down(m->window, MLX_KEY_R))
    {
    }
}