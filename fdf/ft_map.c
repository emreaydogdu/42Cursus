/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/18 17:18:22 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_persv	ft_persv(int projection)
{
	t_persv	persv;

	//persv = (t_persv *)malloc(sizeof(t_persv));
	//if (persv == NULL)
	//	exit(0);
	if (projection == 1)
	{
		persv.a = 1.572f;
		persv.b = 0;
		persv.c = 0;
	}
	else if (projection == 2)
	{
		persv.a = 0;
		persv.b = 0;
		persv.c = 0;
	}
	else
	{
		persv.a = 0.353599f;
		persv.b = -0.353599f;
		persv.c = 0.785398f;
	}
	return (persv);
}

static t_point	ft_point(int x, int y, int z, int color, t_map m)
{
	t_point	point;

	point.x = (float)x;
	point.y = (float)y;
	point.z = (float)z;
	point.color = color;
	if (color == -1)
		point.color = get_default_color(point.z, &m);
	return (point);
}

static void	ft_fill_map(char *file, t_map *m)
{
	int		fd;
	int		y;
	int		x;
	char	*line;
	char	**lines;
	char	**values;
	int		color;

	fd = open(file, O_RDONLY);
	m->map = malloc(sizeof(t_point *) * m->height);
	y = 0;
	while (y < m->height)
		m->map[y++] = malloc(sizeof(t_point) * m->width);
	y = 0;
	while (y < m->height)
	{
		x = 0;
		line = get_next_line(fd);
		lines = ft_split(line, ' ');
		free(line);
		while (lines[x])
		{
			values = ft_split(lines[x], ',');
			if (values[0])
			{
				color = -1;
				if (values[1])
				{
					color = strtol(values[1], NULL, 16) << 8 | 0xFF;
					free(values[1]);
				}
				m->map[y][x] = ft_point(x, y, ft_atoi(values[0]), color, *m);
				free(values[0]);
			}
			free(values);
			free(lines[x]);
			x++;
		}
		free(lines);
		y++;
	}
	close(fd);
}

void	ft_parse_map(char *file, t_map *m)
{
	int		fd;
	char	*line;
	char	**lines;

	fd = open(file, O_RDONLY);
	m->height = 0;
	m->width = 0;
	line = get_next_line(fd);
	lines = ft_split(line, ' ');
	while (lines[m->width])
	{
		free(lines[m->width]);
		m->width++;
	}
	free(lines);
	while (line)
	{
		m->height++;
		free(line);
		line = get_next_line(fd);
	}
	m->image = NULL;
	m->menu = malloc(sizeof(t_menu));
	m->xoff = 0;
	m->yoff = 0;
	m->zoom = 20.0f;
	m->projection = 2;
	m->persv = ft_persv(2);
	close(fd);
	ft_fill_map(file, m);
}
/*
static void	ft_print_map(t_map m)
{
	int	y;
	int	x;

	y = 0;
	while (y < m.height)
	{
		x = -1;
		while (++x < m.width)
			printf("%3d", (int)m.map[y][x].z);
		printf("\n");
		y++;
	}
	printf("%d\n", m.width);
	printf("%d\n", m.height);
}
*/