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

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"

# define ERR_ARGS	"Wrong number of arguments. Only the map path is required."
# define ERR_FILE	"File doesn't exist."
# define ERR_FILEXT	"File has wrong extension. Should be '.ber'"
# define ERR_RECT	"The Map is not rectangular."
# define ERR_CHAR	"The Map contains invalid characters."
# define ERR_PATH	"The Map has no valid path."
# define ERR_NOE	"The Map has no exit."
# define ERR_NOP	"The Map has no player."
# define ERR_NOC	"The Map has no collectible."
# define ERR_DUE	"The Map has duplicate exit."
# define ERR_DUP	"The Map has duplicate player."
# define ERR_WALL	"The Map is not surrounded by walls."

typedef struct s_pos
{
	int	x;
	int	y;

}	t_pos;

typedef struct s_map
{
	mlx_t		*window;
	int			moves;
	int			width;
	int			height;
	char		**map;
	char		**mapcpy;
	int			pcount;
	int			ccount;
	int			ecount;
	int			collected;
	mlx_image_t *collectibles;
	mlx_image_t	*player;
	mlx_image_t	*end1;
	mlx_image_t	*end2;
	mlx_image_t	*wall1;
	mlx_image_t	*wall2;
	mlx_image_t	*wall3;
	mlx_image_t	*wall4;
}	t_map;

void	ft_map_parse(char *file, t_map *m);
void	ft_print_map(t_map m);

void	keyhook(mlx_key_data_t keydata, void *param);

void	draw_water(t_map *m);
void	draw_land(t_map *m);
void	draw_wall(int x, int y, t_map *m);

void	ft_error(char *msg);
void	check_file(char *path);
void	check_rectangle(t_map *m);
void	check_chars(t_map *m);
void	free_mem(t_map *m);
#endif
