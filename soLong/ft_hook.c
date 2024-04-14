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
	if (mlx_is_key_down(m->window, (MLX_KEY_ESCAPE)))
		mlx_close_window(m->window);
	if (mlx_is_key_down(m->window, MLX_KEY_R))
	{
		printf("count c %d\n", m->ccount);
		printf("pos: %d - %d\n", m->pos.x, m->pos.y);
		printf("pos: %d - %d\n", m->end2->pos.x, m->end2->pos.y);
		if (m->pos.x == m->end2->pos.x && m->pos.y == m->end2->pos.y)
			printf("you won\n");
	}
	hook_up_h(m);
	hook_down_h(m);
	hook_left_h(m);
	hook_right_h(m);
}
