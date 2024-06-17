/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:34:16 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/09/25 22:13:26 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*work(void *philo_ptr)
{
	t_philo		*philo;
	pthread_t	monitor_thread;

	philo = (t_philo *)philo_ptr;
	if (philo->id % 2 == 0)
		usleep(100);
	philo->last_meal_time = get_time();
	pthread_create(&monitor_thread, NULL, &monitor, philo);
	while (1)
	{
		monitor_count(philo);
		if (check_finish(*philo) == ERROR)
			break ;
		eat(philo);
		monitor_count(philo);
		if (check_finish(*philo) == ERROR)
			break ;
		sleep_philo(philo);
		think(philo);
		monitor_count(philo);
		if (check_finish(*philo) == ERROR)
			break ;
	}
	pthread_join(monitor_thread, NULL);
	return (0);
}

void	*monitor(void *philo_ptr)
{
	t_philo	*philo;

	philo = (t_philo *)philo_ptr;
	while (1)
	{
		pthread_mutex_lock(&philo->info->dead_mutex);
		if (get_time() - philo->last_meal_time > philo->info->time_to_die
			&& philo->info->dead != 1)
		{
			philo->info->dead = 1;
			pthread_mutex_unlock(&philo->info->dead_mutex);
			print(philo, "died");
			return (0);
		}
		pthread_mutex_lock(&philo->info->finish_mutex);
		if (monitor_finish(*philo))
		{
			pthread_mutex_unlock(&philo->info->dead_mutex);
			pthread_mutex_unlock(&philo->info->finish_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->info->finish_mutex);
		pthread_mutex_unlock(&philo->info->dead_mutex);
	}
	return (0);
}

void	create_threads(t_info *info, pthread_t *th)
{
	int	i;

	i = -1;
	while (++i < info->philo_num)
		pthread_create(&th[i], NULL, &work, &info->philos[i]);
}

void	wait_for_threads(t_info *info, pthread_t *th)
{
	int	i;

	/*
	while (1)
	{
		pthread_mutex_lock(&info->dead_mutex);
		pthread_mutex_lock(&info->finish_mutex);
		if (info->finish_count == info->philo_num || info->dead == 1)
		{
			pthread_mutex_unlock(&info->dead_mutex);
			pthread_mutex_unlock(&info->finish_mutex);
			break ;
		}
		pthread_mutex_unlock(&info->finish_mutex);
		pthread_mutex_unlock(&info->dead_mutex);
	}
	 */
	i = -1;
	while (++i < info->philo_num)
		pthread_join(th[i], NULL);
}

void	exec_philosophers(t_info info)
{
	pthread_t	*th;

	th = (pthread_t *)malloc(sizeof(pthread_t) * info.philo_num);
	if (th == NULL)
		return ;
	create_threads(&info, th);
	wait_for_threads(&info, th);
	free(th);
	clear_data(&info);
}
