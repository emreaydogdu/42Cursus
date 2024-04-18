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

static int	get_wh(const char *filename)
{
	int		fd;
	int		len;
	int		size_read;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	len = 0;
	while (1)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (!size_read)
			break ;
		len += size_read;
	}
	close(fd);
	return (len);
}

static char	*ft_readf(int fd, int count, t_map *m)
{
	char *str;
	char	buffer[1];
	ssize_t	i;

	str = malloc(sizeof(char) * count + 1);
	i = 0;
	while (read(fd, buffer, 1))
	{
		if (*buffer == '\n')
			m->height++;
		str[i++] = *buffer;
	}
	m->height++;
	str[i] = '\0';
	return (str);
}

void	ft_map_parse(char *file, t_map *m)
{
	char *str;
	int	fd;

	check_file(file);
	int	amount =  get_wh(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return ;
	str = ft_readf(fd, amount, m);
	m->map = ft_split(str, '\n');
	m->mapcpy = ft_split(str, '\n');
	m->width = ft_strlen(m->map[0]);
	free(str);
	check_rectangle(m);
	check_chars(m);
	check_path(m);
}