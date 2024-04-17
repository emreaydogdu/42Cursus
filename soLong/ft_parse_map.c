/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/14 23:21:24 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	ft_map_path_fill(char **grid, t_map *m, int x, int y)
{
	if (x < 0 || y < 0 || y >= m->height || x >= m->width || (grid[y][x] != '0'\
		&& grid[y][x] != 'P' && grid[y][x] != 'C' && grid[y][x] != 'E'))
		return ;
	grid[y][x] = 'X';
	ft_map_path_fill(grid, m, x + 1, y);
	ft_map_path_fill(grid, m, x - 1, y);
	ft_map_path_fill(grid, m, x, y + 1);
	ft_map_path_fill(grid, m, x, y - 1);
}

static void	check_path(t_map *m)
{
	int		x;
	int		y;
	t_pos	pos;

	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (m->mapcpy[y][++x])
			if (m->mapcpy[y][x] == 'P')
				pos = (t_pos){x, y};
	}
	ft_map_path_fill(m->mapcpy, m, pos.x, pos.y);
	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (m->mapcpy[y][++x])
			if (m->mapcpy[y][x] == 'E' || m->mapcpy[y][x] == 'C')
				ft_error(ERR_PATH);
	}
}

void	ft_map_parse(char *file, t_map *m)
{
	char *str;

	check_file(file);
	str = ft_file_read(file);
	if (!str)
		ft_error(ERR_FILE);
	m->map = ft_split(str, '\n');
	m->mapcpy = ft_split(str, '\n');
	free(str);
	m->width = ft_strlen(m->map[0]);
	m->height = ft_arrlen(m->map);
	check_rectangle(m);
	check_chars(m);
	check_path(m);
}