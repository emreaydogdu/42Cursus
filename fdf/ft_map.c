/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:15:43 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/12 13:20:45 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static t_persv	*ft_persv(void)
{
	t_persv	*persv;

	persv = (t_persv *)malloc(sizeof(t_persv));
	if (persv == NULL)
		exit(0);
	persv->a = 0;
	persv->b = 0;
	persv->c = 0;
	return (persv);
}

static void	ft_fill_map(char *file, t_map *m)
{
	int		fd;
	int		i;
	int		j;
	char	**lines;
	char	**values;

	fd = open(file, O_RDONLY);
	m->map = malloc(sizeof(t_point *) * m->height);
	i = 0;
	while (i < m->height)
		m->map[i++] = malloc(sizeof(t_point) * m->width);
	i = 0;
	while (i < m->height)
	{
		j = 0;
		lines = ft_split(get_next_line(fd), ' ');
		while (lines[j])
		{
			values = ft_split(lines[j], ',');
			if (values[1])
				printf("%d\n", ft_atoi_base(values[1], 16));
			//m->map[i][j] = *ft_point(i, j, ft_atoi(values[0]), ft_atoi(values[1]), *m);
			j++;
		}
		free(lines);
		i++;
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
		m->width++;
	while (line)
	{
		m->height++;
		line = get_next_line(fd);
	}
	m->zoom = 20;
	m->angle = 0.523599f;
	m->persv = ft_persv();
	m->xoff = 0;
	m->yoff = 0;
	close(fd);
	ft_fill_map(file, m);
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
			printf("%3d ", (int)m.map[i][j++].z);
		printf("\n");
		i++;
	}
	printf("%d\n", m.width);
	printf("%d\n", m.height);
}
