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

typedef struct s_game
{
    int     moves;
    int     failes;

}   t_game;

typedef struct s_map
{
	int			width;
	int			height;
	char		**map;
	mlx_t		*window;
	mlx_image_t *player;
    mlx_image_t *end;
    mlx_image_t *end2;
}	t_map;


// FILE //
void	ft_parse_map(char *file, t_map *m);
void	ft_print_map(t_map m);

// MENU //
void	keyhook(mlx_key_data_t keydata, void *param);

// DRAW //
void    draw_water(t_map m);
void    draw_land(t_map m);
void    draw_obstacle(t_map m);
void	draw_end(t_map m);
void	draw_collect(t_map m);
void	draw_place(t_map m, int x, int y, char* path);
void	draw_line(t_map m, int y, char* path, char* path2, char* path3);
void	draw_img(t_map m, int x, int y, char* path, mlx_image_t *img);

int	ft_atoi_base(const char *str, int str_base);
#endif
