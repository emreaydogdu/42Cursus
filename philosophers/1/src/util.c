/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 20:58:50 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/09/25 21:31:04 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	pick_up_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->forks[philo->id - 1]);
	pthread_mutex_lock(&philo->info->forks[(philo->id)
		%philo->info->philo_num]);
}

void	put_down_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->info->forks[(philo->id)
		%philo->info->philo_num]);
	pthread_mutex_unlock(&philo->info->forks[philo->id - 1]);
}

int	check_finish(t_philo philo)
{
	pthread_mutex_lock(&philo.info->dead_mutex);
	pthread_mutex_lock(&philo.info->finish_mutex);
	if (philo.info->finish_count == philo.info->philo_num
		|| philo.info->dead == 1)
	{
		pthread_mutex_unlock(&philo.info->finish_mutex);
		pthread_mutex_unlock(&philo.info->dead_mutex);
		return (ERROR);
	}
	pthread_mutex_unlock(&philo.info->finish_mutex);
	pthread_mutex_unlock(&philo.info->dead_mutex);
	return (SUCCESS);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print(t_philo *philo, char *action)
{
	pthread_mutex_lock(&philo->info->write);
	printf("%lu	%d %s\n", (unsigned long)get_time(), philo->id, action);
	pthread_mutex_unlock(&philo->info->write);
}
