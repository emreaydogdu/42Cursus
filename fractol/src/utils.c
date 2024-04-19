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
	t_fractal	*frac;

	frac = malloc(sizeof(t_fractal));
	if (!frac)
		pr_error("Error", 0);
	frac->flag = flag;
	frac->mlx = mlx_init();
	frac->win = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "Fractol");
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	frac->addr = mlx_get_data_addr(frac->img, &frac->bits_per_pixel,
		&frac->line_length, &frac->endian);
	frac->zoom = 300;
	frac->offset_x = 0;
	frac->offset_y = 0;
	frac->offset_x = -WIDTH / frac->zoom / 2;
	frac->offset_y = -HEIGHT / frac->zoom / 2;
	frac->z_x = 0;
	frac->z_y = 0;
	frac->c_x = -0.8;
	frac->c_y = 0.2;
	frac->x = 10;
	frac->y = 0;
	frac->max_iter = 100;
	frac->color = BASE_COLOR;
	return (frac);
}

void	random_double(t_fractal *frac)
{
	if (frac->c_x == 0 && frac->c_y == 0)
	{
		frac->c_x = 0;
		frac->c_y = 0.138240;
		return ;
	}
	frac->c_x *= 1.1 * 4 - 2;
	frac->c_y *= 1.1 * 4 - 2;
	if (frac->c_x > 2)
		frac->c_x = 0;
	if (frac->c_y > 2)
		frac->c_y = 0;
}

int	killall_free(t_fractal *frac)
{
	mlx_destroy_image(frac->mlx, frac->img);
	mlx_destroy_window(frac->mlx, frac->win);
	mlx_destroy_display(frac->mlx);
	free(frac->mlx);
	free(frac);
	exit(EXIT_SUCCESS);
}