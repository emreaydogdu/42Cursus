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

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

static int	ft_check_mima(int ac, char **v)
{
	int		i;
	long	res;

	i = 1;
	while (i < ac)
	{
		res = ft_atol(v[i]);
		if (res < -2147483648 || res > 2147483647 
			|| (ft_strlen(v[i]) > 10 && res > 0)
			|| (ft_strlen(v[i]) > 11 && res < 0))
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(int ac, char **av)
{
	if (ac == 1)
		exit(EXIT_SUCCESS);
	if (ft_check_dig(av) || ft_check_dup(ac, av) 
		|| ft_check_mima(ac, av))
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
