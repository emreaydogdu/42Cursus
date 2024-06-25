/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:19:54 by emaydogd          #+#    #+#             */
/*   Updated: 2024/06/25 00:29:32 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

static int	ft_init_mutex(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->count)
	{
		if (pthread_mutex_init(&(table->forks[i]), NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&table->meal, NULL))
		return (1);
	if (pthread_mutex_init(&table->writing, NULL))
		return (1);
	return (0);
}

static int	ft_init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->count)
	{
		table->philos[i].ate_times = 0;
		table->philos[i].pos = i + 1;
		table->philos[i].pos_str = ft_itoa(i + 1);
		if (!table->philos[i].pos_str)
			break ;
		table->philos[i].ffork = i;
		table->philos[i].sfork = (i + 1) % table->count;
		table->philos[i].table = table;
		i++;
	}
	if (i != table->count)
	{
		while (i >= 0)
		{
			free(table->philos[i].pos_str);
			i--;
		}
		return (1);
	}
	return (0);
}

int	ft_init(t_table *table)
{
	table->philos = malloc(sizeof(t_philo) * table->count);
	if (!table->philos)
		return (0);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->count);
	if (!table->forks)
		return (free(table->philos), 0);
	if (ft_init_mutex(table))
		return (free(table->philos), free(table->forks), 0);
	if (ft_init_philo(table))
		return (free(table->philos), free(table->forks), 0);
	return (1);
}
