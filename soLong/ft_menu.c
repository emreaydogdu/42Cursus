/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:43:31 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/11 21:30:42 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"
#include <memory.h>

// 'Encodes' four individual bytes into an int.
static int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_draw_menu(t_map m)
{
	mlx_image_t	*bg;
	char		*s;

	s = "FDF - inforations";
	bg = mlx_new_image(m.window, 256, 1000);
	memset(bg->pixels, 0x70, bg->width * bg->height * sizeof(int32_t));
	mlx_image_to_window(m.window, bg, 0, 0);
	mlx_put_string(m.window, s, 10, 10);
	//mlx_key_hook(m.window, hook, m.window);
}
