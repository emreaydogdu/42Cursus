/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:19:54 by emaydogd          #+#    #+#             */
/*   Updated: 2024/06/24 13:37:21 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

void	philo_print(char *msg, t_philo *philo, int unlock)
{
	char	*timestamp;

	timestamp = ft_itoa(get_time() - philo->table->start_time);
	pthread_mutex_lock(&philo->table->writing);
	if (!philo->table->stop_condition && !philo->table->max_ate)
		printf("%s %s %s\n", timestamp, philo->pos_str, msg);
	if (unlock)
		pthread_mutex_unlock(&philo->table->writing);
	free(timestamp);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->ffork]);
	philo_print("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->table->forks[philo->sfork]);
	philo_print("has taken a fork", philo, UNLOCK);
	pthread_mutex_lock(&philo->table->meal);
	philo_print("is eating", philo, UNLOCK);
	philo->last_ate = get_time();
	pthread_mutex_unlock(&philo->table->meal);
	new_sleep(philo->table->time_to_eat, philo->table);
	philo->ate_times++;
	pthread_mutex_unlock(&philo->table->forks[philo->sfork]);
	pthread_mutex_unlock(&philo->table->forks[philo->ffork]);
}

void	philo_dead(t_table *table, t_philo *philo)
{
	int	i;

	while (!table->max_ate)
	{
		i = -1;
		while (++i < table->count && !table->stop_condition)
		{
			pthread_mutex_lock(&table->meal);
			if ((int)(get_time() - philo[i].last_ate) >= table->time_to_die)
			{
				philo_print("died", &philo[i], LOCK);
				table->stop_condition = 1;
			}
			pthread_mutex_unlock(&table->meal);
		}
		if (table->stop_condition)
			break ;
		i = 0;
		while (table->eat_count_max && i < table->count
			&& philo[i].ate_times >= table->eat_count_max)
			i++;
		table->max_ate = (i == table->count);
	}
}
