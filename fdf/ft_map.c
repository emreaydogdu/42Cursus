/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/17 13:41:20 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

t_persv	*ft_persv(int projection)
{
	t_persv	*persv;

	persv = (t_persv *)malloc(sizeof(t_persv));
	if (persv == NULL)
		exit(0);
	if (projection == 1)
	{
		persv->a = 1.572f;
		persv->b = 0;
		persv->c = 0;
	}
	else if (projection == 2)
	{
		persv->a = 0;
		persv->b = 0;
		persv->c = 0;
	}
	else
	{
		persv->a = 0.353599f;
		persv->b = -0.353599f;
		persv->c = 0.785398f;
	}
	return (persv);
}

static t_point	*ft_point(int x, int y, int z, int color, t_map m)
{
	t_point	*point;

	point = (t_point *)malloc(sizeof(t_point));
	if (point == NULL)
		mlx_terminate(m.window);
	point->x = (float)x;
	point->y = (float)y;
	point->z = (float)z;
	point->color = color;
	if (!point->color && point->z)
		point->color = 0xFFFFFF;
	else if (!point->color)
		point->color = 0xFF1B30;
	return (point);
}

static void	ft_fill_map(char *file, t_map *m)
{
	int		fd;
	int		y;
	int		x;
	char	**lines;
	char	**values;

	fd = open(file, O_RDONLY);
	m->map = malloc(sizeof(t_point *) * m->height);
	y = 0;
	while (y < m->height)
		m->map[y++] = malloc(sizeof(t_point) * m->width);
	y = 0;
	while (y < m->height)
	{
		x = 0;
		lines = ft_split(get_next_line(fd), ' ');
		while (lines[x])
		{
			values = ft_split(lines[x], ',');
			if (values[0])
			{
				if (values[1])
					printf("%d\n", ft_atoi_base(values[1], 10));
				m->map[y][x] = *ft_point(x, y, ft_atoi(values[0]) / 10, 0, *m);
			}
			x++;
		}
		free(lines);
		y++;
	}
	close(fd);
}

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
		m->width++;
	while (line)
	{
		m->height++;
		line = get_next_line(fd);
	}
	m->image = malloc(sizeof(mlx_image_t));
	m->menu = malloc(sizeof(t_menu));
	m->xoff = 0;
	m->yoff = 0;
	m->zoom = 20.0f;
	m->projection = 2;
	m->persv = ft_persv(2);
	close(fd);
	ft_fill_map(file, m);
}
