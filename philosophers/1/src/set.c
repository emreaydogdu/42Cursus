/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:39:36 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/09/25 21:49:05 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	set_basic(t_info *info, char **argv)
{
	info->dead = 0;
	info->philo_num = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = -1;
	info->finish_count = 0;
}

int	init_philo(t_info *info, int argc, char **argv)
{
	pthread_mutex_t	write;
	pthread_mutex_t	*fork;
	pthread_mutex_t	dead;
	pthread_mutex_t	finish;
	int				i;

	set_basic(info, argv);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * info->philo_num);
	if (fork == NULL)
		return (ERROR);
	i = -1;
	while (++i < info->philo_num)
		pthread_mutex_init(&fork[i], 0);
	pthread_mutex_init(&write, 0);
	pthread_mutex_init(&finish, 0);
	pthread_mutex_init(&dead, 0);
	info->forks = fork;
	info->dead_mutex = dead;
	info->write = write;
	info->finish_mutex = finish;
	//info->philos = set_philosopher(info->philo_num, *info);
	return (SUCCESS);
}

void	set_philosopher_param(t_philo *philo, t_info *info, int i)
{
	philo->info = info;
	philo->eat_count = 0;
	philo->eating = 0;
	philo->finish_flag = 0;
	philo->last_meal_time = get_time();
	philo->id = i + 1;
}

t_philo	*set_philosopher(int num, t_info info)
{
	t_philo			*philo;
	pthread_mutex_t	dead;
	int				i;

	i = 0;
	philo = (t_philo *)malloc(sizeof(t_philo) * num);
	if (philo == NULL)
		return (NULL);
	pthread_mutex_init(&dead, 0);
	while (i < num)
	{
		set_philosopher_param(&philo[i], &info, i);
		i++;
	}
	philo->dead_mutex = dead;
	return (philo);
}
