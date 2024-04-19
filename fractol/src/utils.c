/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:09:28 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:11:14 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"

int	check_args(int argc, char **argv)
{
	int	valid;

	valid = 0;
	if (argc < 2)
		pr_error(ERR_ARGS, 1);
	if (!ft_strncmp(argv[1], "--help\0", 7) || !ft_strncmp(argv[1], "-h\0", 3))
		pr_error(INSTRUCTIONS, 0);
	else if (!ft_strncmp(argv[1], "--mandelbrot\0", 13) \
		|| !ft_strncmp(argv[1], "-m\0", 3))
		valid = 1;
	else if (!ft_strncmp(argv[1], "--julia\0", 8) \
		|| !ft_strncmp(argv[1], "-j\0", 3))
		valid = 2;
	else
		pr_error(ERR_ARGS, 1);
	return (valid);
}

t_fractal	*frac_init(int flag)
{
	t_fractal	*fract;

	fract = malloc(sizeof(t_fractal));
	if (!fract)
		pr_error("Error", 0);
	fract->flag = flag;
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, WIDTH, HEIGHT, "Fractol");
	fract->img = mlx_new_image(fract->mlx, WIDTH, HEIGHT);
	fract->addr = mlx_get_data_addr(fract->img, &fract->bits_per_pixel,
			&fract->line_length, &fract->endian);
	fract->zoom = 300;
	fract->offset_x = 0;
	fract->offset_y = 0;
	fract->offset_x = -WIDTH / fract->zoom / 2;
	fract->offset_y = -HEIGHT / fract->zoom / 2;
	fract->z_x = 0;
	fract->z_y = 0;
	fract->c_x = -0.8;
	fract->c_y = 0.2;
	fract->x = 10;
	fract->y = 0;
	fract->max_iter = 100;
	fract->color = BASE_COLOR;
	return (fract);
}

void	random_double(t_fractal *fract)
{
	if (fract->c_x == 0 && fract->c_y == 0)
	{
		fract->c_x = -0.8;
		fract->c_y = 0.2;
		return ;
	}
	fract->c_x *= 1.1 * 4 - 2;
	fract->c_y *= 1.1 * 4 - 2;
	if (fract->c_x > 2)
		fract->c_x = 0;
	if (fract->c_y > 2)
		fract->c_y = 0;
}

int	killall_free(t_fractal *fract)
{
	mlx_destroy_image(fract->mlx, fract->img);
	mlx_destroy_window(fract->mlx, fract->win);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	free(fract);
	exit(EXIT_SUCCESS);
}
