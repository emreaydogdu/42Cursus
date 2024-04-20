/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:08:32 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:12:17 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	*fract;

	fract = frac_init(check_args(argc, argv));
	if (fract->flag == 2 && argc == 4)
	{
		fract->c_x = ft_strtof(argv[2]);
		fract->c_y = -ft_strtof(argv[3]);
	}
	draw_fractal(fract);
	mlx_key_hook(fract->win, key_hook, fract);
	mlx_mouse_hook(fract->win, mouse_hook, fract);
	mlx_hook(fract->win, 17, 0L, killall_free, fract);
	mlx_loop(fract->mlx);
	return (0);
}
