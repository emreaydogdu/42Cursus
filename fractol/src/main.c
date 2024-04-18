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
	int			flag;
	t_fractal	*fractal;

	flag = check_args(argc, argv);
	fractal = malloc(sizeof(t_fractal));
	if (!fractal)
		return (-1);
	frac_init(fractal, flag);
	if (fractal->flag == 2)
	{
		if (argc == 5)
		{
			fractal->c_x = ft_strtof(argv[2]);
			fractal->c_y = ft_strtof(argv[3]);
		}
		else
			random_double(fractal);
	}
	draw_fractal(fractal);
	mlx_key_hook(fractal->win, key_hook, fractal);
	mlx_mouse_hook(fractal->win, mouse_hook, fractal);
	mlx_hook(fractal->win, 17, 0L, killall_free, fractal);
	mlx_loop(fractal->mlx);
	return (0);
}
