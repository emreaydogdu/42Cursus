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

void	my_keyhook(mlx_key_data_t keydata, void* param)
{
	t_map	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx->window, MLX_KEY_M))
		mlx_delete_image(mlx->window, mlx->image);
	if (mlx_is_key_down(mlx->window, MLX_KEY_UP))
		mlx->image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx->window, MLX_KEY_DOWN))
		mlx->image->instances[0].y += 5;
	if (mlx_is_key_down(mlx->window, MLX_KEY_LEFT))
		mlx->image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx->window, MLX_KEY_RIGHT))
		mlx->image->instances[0].x += 5;
	if (mlx_is_key_down(mlx->window, MLX_KEY_Q))
	{
		if (mlx->persv->a < 2.0f)
			mlx->persv->a += 0.03f;
	}
	if (mlx_is_key_down(mlx->window, MLX_KEY_W))
	{
		if (mlx->persv->a > 0.0f)
			mlx->persv->a -= 0.03f;
	}
	if (mlx_is_key_down(mlx->window, MLX_KEY_A))
	{
		if (mlx->persv->b < 2.0f)
			mlx->persv->b += 0.03f;
	}
	if (mlx_is_key_down(mlx->window, MLX_KEY_S))
	{
		if (mlx->persv->b > 0.0f)
			mlx->persv->b -= 0.03f;
	}
	if (mlx_is_key_down(mlx->window, MLX_KEY_E))
	{
		if (mlx->persv->c < 2.0f)
			mlx->persv->c += 0.03f;
	}
	if (mlx_is_key_down(mlx->window, MLX_KEY_R))
	{
		if (mlx->persv->c > 0.0f)
			mlx->persv->c -= 0.03f;
	}
	mlx_delete_image(mlx->window, mlx->image);
	mlx->image = mlx_new_image(mlx->window, 1400, 1000);
	ft_draw(*mlx);
	mlx_image_to_window(mlx->window, mlx->image, 0, 0);
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
