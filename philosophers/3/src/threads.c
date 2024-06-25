/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:19:54 by emaydogd          #+#    #+#             */
/*   Updated: 2024/06/24 13:37:34 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

static void	*routine(void *params)
{
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)params;
	table = philo->table;
	if (philo->pos % 2 && table->count > 1)
		new_sleep(table->time_to_eat / 50, table);
	while (!table->stop_condition && !table->max_ate)
	{
		philo_eat(philo);
		philo_print("is sleeping", philo, UNLOCK);
		new_sleep(table->time_to_sleep, table);
		philo_print("is thinking", philo, UNLOCK);
	}
	return (NULL);
}

static void	exit_threads(t_table *table)
{
	int	i;

	if (table->count == 1)
		pthread_detach(table->philos[0].thread_id);
	else
	{
		i = -1;
		while (++i < table->count)
			pthread_join(table->philos[i].thread_id, NULL);
	}
	i = -1;
	while (++i < table->count)
		pthread_mutex_destroy(&table->forks[i]);
	pthread_mutex_destroy(&table->meal);
	pthread_mutex_destroy(&table->writing);
	i = -1;
	while (++i < table->count)
		free(table->philos[i].pos_str);
	free(table->philos);
	free(table->forks);
}

int	start_threads(t_table *table)
{
	int	i;

	i = -1;
	table->start_time = get_time();
	while (++i < table->count)
	{
		table->philos[i].last_ate = get_time();
		if (pthread_create(&table->philos[i].thread_id,
				NULL, routine, &(table->philos[i])))
			return (0);
	}
	philo_dead(table, table->philos);
	pthread_mutex_unlock(&table->writing);
	exit_threads(table);
	return (1);
}
