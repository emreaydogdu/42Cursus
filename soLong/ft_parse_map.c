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

static void	ft_map_check_path(t_map *m)
{
	int	x;
	int	y;

	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (m->mapcpy[y][++x])
			if (m->mapcpy[y][x] == 'P')
				m->pos = (t_pos){x, y};
	}
	ft_map_path_fill(m->mapcpy, m, m->pos.x, m->pos.y);
	y = -1;
	while (++y < m->height)
	{
		x = -1;
		while (m->mapcpy[y][++x])
			if (m->mapcpy[y][x] == 'E' || m->mapcpy[y][x] == 'C')
				ft_error("ERR_PATH", m);
	}
}

static void	ft_map_check_char_err(t_map *m)
{
	if (m->ecount == 0)
		ft_error("ERR_NO_E", m);
	if (m->pcount > 1)
		ft_error("ERR_DUP_P", m);
	if (m->pcount == 0)
		ft_error("ERR_NO_P", m);
	if (m->ecount > 1)
		ft_error("ERR_DUP_E", m);
	if (m->ecount > 1)
		ft_error("ERR_DUP_E", m);
	if (m->ccount == 0)
		ft_error("ERR_NO_C", m);
	/*
	if (m->width != j)
		ft_perror_exit(ERR_WIDTH, game);
	*/
}

static void	ft_map_check_chars(t_map *m)
{
	int		i;
	int		j;

	i = -1;
	while (i++ < m->height - 1)
	{
		j = -1;
		while (j++ < m->width - 1)
		{
			if ((i == 0 || i == m->height - 1 || j == 0 || j == m->width - 1) \
				&& m->map[i][j] != '1')
				ft_error("ERR_WALL", m);
			else if (m->map[i][j] == 'C')
				m->ccount++;
			else if (m->map[i][j] == 'P')
				m->pcount++;
			else if (m->map[i][j] == 'E')
				m->ecount++;
			else if (m->map[i][j] != '1' && m->map[i][j] != '0')
				ft_error("ERR_CHAR", m);
		}
	}
	ft_map_check_char_err(m);
}

static void	ft_map_fill(char *file, t_map *m, int fd)
{
	int		i;
	char	*lines;

	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	m->map = malloc(sizeof(char *) * m->height);
	m->mapcpy = malloc(sizeof(char *) * m->height);
	if (m->map == NULL || m->mapcpy == NULL)
		return ;
	i = -1;
	lines = get_next_line(fd);
	while (lines)
	{
		m->map[++i] = malloc(sizeof(char) * (m->width));
		m->mapcpy[i] = malloc(sizeof(char) * (m->width));
		if (m->map[i] == NULL || m->mapcpy[i] == NULL)
			return ;
		ft_memcpy(m->map[i], lines, m->width);
		ft_memcpy(m->mapcpy[i], lines, m->width);
		free(lines);
		lines = get_next_line(fd);
	}
	close(fd);
}

void	ft_map_parse(char *file, t_map *m)
{
	int		fd;
	char	*line;

	m->height = 0;
	m->width = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	line = get_next_line(fd);
	while (line[m->width] != '\n')
		m->width++;
	while (line)
	{
		free(line);
		m->height++;
		line = get_next_line(fd);
	}
	ft_map_fill(file, m, fd);
}

void	ft_map_check(char *file, t_map *m)
{
	ft_map_parse(file, m);
	ft_map_check_chars(m);
	//ft_map_check_path(m);
}

void	ft_print_map(t_map m)
{
	int	i;
	int	j;

	i = 0;
	while (i < m.height)
	{
		j = 0;
		while (j < m.width)
			printf("%3c ", m.map[i][j++]);
		printf("\n");
		i++;
	}
	printf("%d\n", m.width);
	printf("%d\n", m.height);
}
