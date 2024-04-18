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
#include "so_long.h"

static void	check_end(t_map *m)
{
	if (m->ccount == m->collected)
	{
		m->end1->instances[0].enabled = false;
		m->end2->instances[0].enabled = true;
		if (m->player->instances[0].x == m->end1->instances[0].x && \
			m->player->instances[0].y == m->end1->instances[0].y)
		{
			mlx_terminate(m->window);
			exit(EXIT_SUCCESS);
			return ;
		}
	}
}

static void	check_collectibles(int x, int y, t_map *m)
{
	int				i;
	mlx_instance_t	collect;

	i = -1;
	while (++i < m->ccount)
	{
		collect = m->collectibles->instances[i];
		if (collect.x == x && collect.y == y && collect.enabled)
		{
			m->collectibles->instances[i].enabled = false;
			m->collected++;
		}
	}
	check_end(m);
}

static void	hook_move(int x, int y, t_map *m)
{
	if (m->map[y / 32 - 1][x / 32 - 1] == 'C' || m->map[y / 32 - 1][x / 32 - 1] \
		== '0' || (m->map[y / 32 - 1][x / 32 - 1] == 'E' && m->end1->enabled))
	{
		m->player->instances[0].x = x;
		m->player->instances[0].y = y;
		check_collectibles(x, y, m);
		printf("Moves count: %d\n", ++m->moves);
	}
}

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map			*m;
	mlx_instance_t	player;

	m = param;
	(void) keydata;
	player = m->player->instances[0];
	if (mlx_is_key_down(m->window, (MLX_KEY_ESCAPE)))
	{
		
		mlx_terminate(m->window);
		exit(EXIT_SUCCESS);
		return ;
	}
	if (mlx_is_key_down(m->window, MLX_KEY_UP))
		hook_move(player.x, player.y - 32, m);
	else if (mlx_is_key_down(m->window, MLX_KEY_DOWN))
		hook_move(player.x, player.y + 32, m);
	else if (mlx_is_key_down(m->window, MLX_KEY_RIGHT))
		hook_move(player.x + 32, player.y, m);
	else if (mlx_is_key_down(m->window, MLX_KEY_LEFT))
		hook_move(player.x - 32, player.y, m);
}

void	ft_close_hook(void *param)
{
	t_map	*m;

	m = param;
	printf("Closing Program\n");
	//free_mem(m);
}
