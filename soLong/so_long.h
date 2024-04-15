/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:49:53 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/12 13:17:47 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <sys/fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "getNextLine/get_next_line.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10
# endif
# define ERR_ARGS	"Wrong number of arguments. Only the map path is required."

typedef struct s_pos
{
	int	x;
	int	y;

}	t_pos;

typedef struct s_col
{
	int			x;
	int			y;
	mlx_image_t	*col;

}	t_col;

typedef struct s_end
{
	t_pos		pos;
	mlx_image_t	*img;

}	t_end;

typedef struct s_map
{
	int			moves;
	int			width;
	int			height;
	char		**map;
	char		**mapcpy;
	mlx_t		*window;
	t_pos		pos;
	mlx_image_t	*player;
	t_col		**collections;
	t_end 		*end;
	t_end 		*end2;
	int			pcount;
	int			ccount;
	int			ecount;
}	t_map;

void	ft_map_check(char *file, t_map *m);
void	ft_map_parse(char *file, t_map *m);
void	ft_print_map(t_map m);

void	keyhook(mlx_key_data_t keydata, void *param);
void	hook_up_h(t_map *m);
void	hook_down_h(t_map *m);
void	hook_left_h(t_map *m);
void	hook_right_h(t_map *m);
void	find_collectibles(int x, int y, t_map *m);

void	draw_water(t_map *m);
void	draw_land(t_map *m);
void	draw_obstacle(t_map *m);
void	draw_end(t_map *m);
void	draw_collect(t_map *m);
void	draw_player(t_map *m);
void	draw_place(t_map *m, int x, int y, char *path);
void	draw_line(t_map *m, int y, char *path, char *path2, char *path3);

void	ft_error(char *msg, t_map *m);
void	free_mem(t_map *m);
#endif
