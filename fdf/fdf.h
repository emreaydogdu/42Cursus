/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:49:53 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/17 18:16:03 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "MLX/MLX42.h"
# include "libft/libft.h"
# include "getNextLine/get_next_line.h"

# define ABS(a) ((a < 0) ? -a : a)

# define TEXT_COLOR			0xEAEAEA
# define BACKGROUND			0x222222
# define MENU_BACKGROUND	0x1E1E1E

# define COLOR_DISCO		0x9A1F6AFF
# define COLOR_BRICK_RED	0xC2294EFF
# define COLOR_FLAMINGO		0xEC4B27FF
# define COLOR_JAFFA		0xEF8633FF
# define COLOR_SAFFRON		0xF3AF3DFF

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}	t_point;

typedef struct s_persv
{
	float	a;
	float	b;
	float	c;
}	t_persv;

typedef struct s_menu {
	mlx_image_t	*bg;
	mlx_image_t	*bgm;
	mlx_image_t	*mouse_pos;
	mlx_image_t	*xoff;
	mlx_image_t	*yoff;
	mlx_image_t	*zoff;
	mlx_image_t	*yaw;
	mlx_image_t	*pitch;
	mlx_image_t	*roll;
	mlx_image_t	*zoom;
}	t_menu;

typedef struct s_map
{
	int			width;
	int			height;
	float		zoom;
	float		xoff;
	float		yoff;
	int			projection;
	int32_t		mx;
	int32_t		my;
	int32_t		pmx;
	int32_t		pmy;
	t_menu		*menu;
	t_point		**map;
	t_persv		persv;
	mlx_image_t	*image;
	mlx_t		*window;
}	t_map;


// FILE //
void	ft_parse_map(char *file, t_map *m);

// DRAW //
t_persv	ft_persv(int projection);
void	ft_draw_image(t_map *m);

// HOOKS //
void	keyhook(mlx_key_data_t key, void *param);
void	scrollhook(double xdelta, double ydelta, void *param);
void	mousehook(mouse_key_t k, action_t a, modifier_key_t mk, void *param);
void	cursorhook(double xdelta, double ydelta, void *param);
void	closehook(void *param);

// MENU //
void	ft_draw_menu(t_map *m);
void	ft_free_map(t_map *m);

// COLORS //
float	percent(float start, float end, float current);
int		get_color(t_point current, t_point start, t_point end, int delta);
int		get_default_color(int z, t_map *map);

int		ft_atoi_base(const char *str, int str_base);
#endif
