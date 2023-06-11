/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 00:49:53 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/11 16:24:51 by emaydogd         ###   ########.fr       */
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

# define MOD(a) ((a < 0) ? -a : a)

typedef struct s_map
{
	int			width;
	int			height;
	int			**map;
	mlx_t		*window;
	mlx_image_t	*image;
}	t_map;

// FILE //
void	ft_parse_map(char *file, t_map *m);
void	ft_print_map(t_map m);

// DRAW //
void	ft_draw(t_map m);

#endif
