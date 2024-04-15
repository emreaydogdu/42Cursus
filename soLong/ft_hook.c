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

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_map	*m;

	m = param;
	(void) keydata;
	if (mlx_is_key_down(m->window, (MLX_KEY_ESCAPE)))
	{
		free_mem(m);
		mlx_close_window(m->window);
	}
	hook_up_h(m);
	hook_down_h(m);
	hook_left_h(m);
	hook_right_h(m);
}
