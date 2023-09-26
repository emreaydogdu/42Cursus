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
	int	*lst;

	lst = calloc(ac, sizeof(int));
	i = 0;
	while (++i < ac)
		lst[i] = ft_atoi(av[i]);
	i = 0;
	while (++i < ac)
		lst[ft_atoi(av[i]) % ac] = lst[ft_atoi(av[i]) % ac] + ac;
	i = 0;
	while (i < ac)
	{
		if (lst[i] >= ac * 2)
			return (1);
		i++;
	}
	free(lst);
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
		while (v[i][++j])
			if (!ft_isdigit(v[i][j]) && v[i][j] != '-')
				return (1);
	}
	return (0);
}

void	ft_error(int ac, char **av)
{
	if (ac == 1 || ft_check_dig(av) || !ft_check_dup(ac - 1, av))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
