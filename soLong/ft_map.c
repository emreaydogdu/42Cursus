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
	char	*lines;

	fd = open(file, O_RDONLY);
	m->map = malloc(sizeof(t_point *) * m->height);
	i = 0;
	while (i < m->height)
		m->map[i++] = malloc(sizeof(t_point) * m->width);
	i = 0;
	while (i < m->height)
	{
		j = 0;
		lines = get_next_line(fd);
		while (lines[j])
		{
			m->map[i][j] = *ft_point(i, j, lines[j], *m);
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

	fd = open(file, O_RDONLY);
	m->height = 0;
	m->width = 0;
	line = get_next_line(fd);
	while (line[m->width] != '\n')
		m->width++;
	while (line)
	{
		m->height++;
		line = get_next_line(fd);
	}
	m->player = malloc(sizeof(mlx_image_t));
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
			printf("%3c ", (int)m.map[i][j++].z);
		printf("\n");
		i++;
	}
	printf("%d\n", m.width);
	printf("%d\n", m.height);
}
