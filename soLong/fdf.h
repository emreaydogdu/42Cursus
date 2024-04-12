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
	mlx_image_t	*image;
	mlx_image_t	*player;
}	t_map;


// FILE //
void	ft_parse_map(char *file, t_map *m);
void	ft_print_map(t_map m);

// MENU //
void	keyhook(mlx_key_data_t keydata, void* param);
void	close_hook(void *param);

int	ft_atoi_base(const char *str, int str_base);
#endif
