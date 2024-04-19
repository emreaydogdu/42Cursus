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
	t_fractal	*frac;

	frac = frac_init(check_args(argc, argv));
	if (frac->flag == 2 && argc == 4)
	{
		frac->c_x = ft_strtof(argv[2]);
		frac->c_y = ft_strtof(argv[3]);
	}
	draw_fractal(frac);
	mlx_key_hook(frac->win, key_hook, frac);
	mlx_mouse_hook(frac->win, mouse_hook, frac);
	mlx_hook(frac->win, 17, 0L, killall_free, frac);
	mlx_loop(frac->mlx);
	return (0);
}
