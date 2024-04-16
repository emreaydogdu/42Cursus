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

void	check_end(t_map *m)
{
	if (m->ccount == 0)
	{
		m->end->img->enabled = false;
		m->end2->img->enabled = true;
	}
	if (m->pos.x == m->end2->pos.x && m->pos.y == m->end2->pos.y)
	{
		free_mem(m);
		mlx_close_window(m->window);
	}
}

void	find_collectibles(int x, int y, t_map *m)
{
	int	i;

	i = -1;
	m->ccount = 0;
	
	/*
	while (m->collections[++i])
	{
		if (m->collections[i]->x == x && m->collections[i]->y == y \
			&& m->collections[i]->col->enabled)
		{
			m->collections[i]->col->enabled = false;
			m->map[y][x] = '0';
			m->ccount--;
			m->collected++;
		}
	}*/
	check_end(m);
}
