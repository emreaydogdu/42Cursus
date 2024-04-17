/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/14 23:28:42 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_error(char *msg)
{
	printf("%s\n", msg);
	exit(EXIT_FAILURE);
}

void	check_file(char *path)
{
	char *extention;

	extention = ft_strchr(path, '.');
	if (extention)
	{
		if (ft_strlen(extention) != 4)
			ft_error(ERR_FILEXT);
		if (ft_strncmp(extention, ".ber", ft_strlen(extention)) != 0)
			ft_error(ERR_FILEXT);
	} else
		ft_error(ERR_FILEXT);
}

void	check_rectangle(t_map *m)
{
	int	i;

	i = -1;
	while (m->map[++i])
		if ((int)ft_strlen(m->map[i]) != m->width)
			ft_error(ERR_RECT);
}

static void	check_char_err(t_map *m)
{
	if (m->ecount == 0)
		ft_error(ERR_NOE);
	if (m->pcount > 1)
		ft_error(ERR_DUP);
	if (m->pcount == 0)
		ft_error(ERR_NOP);
	if (m->ecount > 1)
		ft_error(ERR_DUE);
	if (m->ccount == 0)
		ft_error(ERR_NOC);
}

void	check_chars(t_map *m)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= m->height - 1)
	{
		j = -1;
		while (++j <= m->width - 1)
		{
			if ((i == 0 || i == m->height - 1 || j == 0 || j == m->width - 1) \
				&& m->map[i][j] != '1')
				ft_error(ERR_WALL);
			else if (m->map[i][j] == 'C')
				m->ccount++;
			else if (m->map[i][j] == 'P')
				m->pcount++;
			else if (m->map[i][j] == 'E')
				m->ecount++;
			else if (m->map[i][j] != '1' && m->map[i][j] != '0')
				ft_error(ERR_CHAR);
		}
	}
	check_char_err(m);
}
