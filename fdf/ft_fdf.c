/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 23:53:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/11 16:30:51 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

int	main(int argc, char **argv)
{
	t_map	m;

	if (argc == 2)
	{
		ft_parse_map(argv[1], &m);
		m.window = mlx_init(1000, 1000, "fdf", true);
		m.image = mlx_new_image(m.window, 1000, 1000);
		ft_draw(m);
		mlx_image_to_window(m.window, m.image, 40, 40);
		mlx_loop(m.window);
	}
	return (EXIT_SUCCESS);
}
