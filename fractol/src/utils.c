/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:26:09 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 13:38:00 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void	frac_init(t_fractal *fractal, char *title, int flag)
{
	fractal->flag = flag;
	fractal->mlx = mlx_init();
	fractal->win = mlx_new_window(fractal->mlx, WIDTH, HEIGHT, title);
	fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	fractal->addr = mlx_get_data_addr(fractal->img, &fractal->bits_per_pixel,
			&fractal->line_length, &fractal->endian);
	fractal->offset_x = -2.1;
	fractal->offset_y = -1.21;
	fractal->z_y = 0;
	fractal->z_x = 0;
	fractal->c_y = 0;
	fractal->c_x = 0;
	fractal->x = 0;
	fractal->y = 0;
	fractal->zoom = 300;
	if (flag == 3)
		fractal->max_iter = 30;
	else
		fractal->max_iter = 100;
	fractal->color = BASE_COLOR;
	fractal->color_shift_step = (255 * 255 * 255) / 100;
	fractal->color_shift_max = 0xFFFFFF;
	fractal->color_shift_min = 0x000000;
	ft_printf("Fractal Initialized.\n");
}

int	killall_free(t_fractal *fractal)
{
	ft_printf("ESC pressed!\n");
	ft_printf("Killing all processes...\n");
	mlx_destroy_image(fractal->mlx, fractal->img);
	mlx_destroy_window(fractal->mlx, fractal->win);
	mlx_destroy_display(fractal->mlx);
	free(fractal->mlx);
	free(fractal);
	ft_printf("Memory Cleared.\nExiting...\n");
	exit(1);
	return (0);
}

int	check_valid(char *arg)
{
	if (!ft_strncmp(arg, "--mandelbrot\0", 13) || !ft_strncmp(arg, "-m\0", 3))
		return (1);
	else if (!ft_strncmp(arg, "--julia\0", 8) || !ft_strncmp(arg, "-j\0", 3))
		return (2);
	else if (!ft_strncmp(arg, "--burning-ship\0", 15)
		|| !ft_strncmp(arg, "-bs\0", 4))
		return (3);
	else if (!ft_strncmp(arg, "--tricorn\0", 10) || !ft_strncmp(arg, "-t\0", 3))
		return (4);
	else
		return (0);
}

int	check_args(int argc, char **argv)
{
	int	valid;

	if (argc < 2)
	{
		ft_printf("Error: missing argument!\n");
		ft_printf("%s", INSTRUCTIONS);
		exit(1);
	}
	if (!ft_strncmp(argv[1], "--help\0", 7) || !ft_strncmp(argv[1], "-h\0", 3))
	{
		ft_printf("%s", INSTRUCTIONS);
		exit(1);
	}
	valid = check_valid(argv[1]);
	if (valid == 0)
	{
		ft_printf("Error: invalid argument!\n");
		ft_printf("%s", INSTRUCTIONS);
		exit(1);
	}
	return (valid);
}

void	random_double(t_fractal *fractal)
{
	if (fractal->c_x == 0 && fractal->c_y == 0)
	{
		fractal->c_x = 0;
		fractal->c_y = 0.138240;
		return ;
	}
	fractal->c_x *= 1.1 * 4 - 2;
	fractal->c_y *= 1.1 * 4 - 2;
	if (fractal->c_x > 2)
		fractal->c_x = 0;
	if (fractal->c_y > 2)
		fractal->c_y = 0;
}
