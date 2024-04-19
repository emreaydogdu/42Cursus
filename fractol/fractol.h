/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:06:51 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:14:48 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

/*
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <time.h>
# include <stdbool.h>
# include <limits.h>
 */
# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# define WIDTH 1080
# define HEIGHT 720
# define INSTRUCTIONS "\n\
 _________________________________________________\n\
| Usage: ./fractol --mandelbrot (-m)              |\n\
|                  --julia (-j) (double) (double) |\n\
|                  --help (-h)                    |\n\
|_________________________________________________|\n"

#define ERR_ARGS "Error: missing argument!"

# define BASE_COLOR 20
# define WHITE 0x00FFFFFF
# define C_STEP 0.1
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define UP 65362
# define DOWN 65364
# define PLUS 61
# define MINUS 45
# define SPACE 32
# define BACKSPACE 65288
# define R 114
# define F 102
# define J 106
# define K 107
# define L 108
# define ONE 49
# define WHEEL_UP 4
# define WHEEL_DOWN 5
# define LEFT_CLICK 1
# define RIGHT_CLICK 3

typedef struct s_fractal
{
	int		flag;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	offset_x;
	double	offset_y;
	int		x;
	int		y;
	double	z_y;
	double	z_x;
	double	c_y;
	double	c_x;
	double	zoom;
	int		max_iter;
	int		color;
}	t_fractal;

t_fractal	*frac_init(int flag);
int			killall_free(t_fractal *fract);
int			check_args(int argc, char **argv);
void		random_double(t_fractal *fract);
void		pr_error(char *msg, int ins);

int			key_hook(int keycode, t_fractal *fract);
void		key_hook3(int keycode, t_fractal *fract);
void		key_hook5(int keycode, t_fractal *fract);
int			mouse_hook(int button, int x, int y, t_fractal *fract);

void		draw_fractal(t_fractal *fractal);
void		draw_infos(t_fractal *fract);
void		put_pixel(t_fractal *data, int x, int y, int color);

void		*draw_mandelbrot(t_fractal *fract);
void		*draw_julia(t_fractal *fract);
int			julia_hook(int keycode, t_fractal *fract);
void		reset_julia(t_fractal *fract);

#endif