/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:49:02 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 23:26:11 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_check_dup(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = ++i;
		while (j < ac)
		{
			if (ft_atoi(av[i - 1]) == ft_atoi(av[j++]))
				return (1);
		}
	}
	return (0);
}

static int	ft_check_dig(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[++i])
	{
		j = -1;
		if (ft_strlen(v[i]) == 0)
			return (1);
		while (v[i][++j])
		{
			if (!ft_isdigit(v[i][j]) && v[i][j] != '-')
				return (1);
		}
	}
	return (0);
}

void	ft_error(int ac, char **av)
{
	if (ac == 1 || ft_check_dig(av) || ft_check_dup(ac, av))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
