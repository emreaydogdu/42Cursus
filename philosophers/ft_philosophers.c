/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:18:56 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/22 01:20:33 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ft_philosophers.h"

long	getTime()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	return(time.tv_sec * 1000 + time.tv_usec/1000);
}

void *eat(void *p)
{
	t_philo	*philo;
	int		leftFork;
	int		rightFork;
	int		iseating;

	philo = (t_philo *)p;
	leftFork = philo->pos;
	rightFork = (philo->pos + 1) % philo->table->num_philos;
	iseating = 0;

	while(philo->num_must_eat > 0)
	{
		printf("%ld %ld is thinking\n", getTime(), philo->pos);
		if (getTime() - philo->time_last_eat > philo->table->time_to_die)
		{
			printf("%ld %ld died\n", getTime(), philo->pos);
			pthread_mutex_unlock(&philo->table->lock);
			break;
		}
		pthread_mutex_lock(&philo->table->lock);
		if(philo->table->forks[leftFork] == 1 && philo->table->forks[rightFork] == 1){
			philo->table->forks[leftFork]  = 0;
			philo->table->forks[rightFork] = 0;
			printf("%ld %ld has taken a fork\n", getTime(), philo->pos);
			philo->num_must_eat--;
			iseating = 1;
		}
		if(iseating){
			printf("%ld %ld is eating\n", getTime(), philo->pos);
			usleep(philo->table->time_to_eat);
			philo->time_last_eat = getTime();
			philo->table->forks[leftFork]  = 1;
			philo->table->forks[rightFork] = 1;
			iseating = 0;
		}
		pthread_mutex_unlock(&philo->table->lock);
		printf("%ld %ld is sleeping\n", getTime(), philo->pos);
		usleep(philo->table->time_to_sleep);


	}
	pthread_exit (NULL);
}

int main(int argc, const char * argv[])
{
	t_table	table;

	pthread_mutex_init(&table.lock, NULL);
	table.num_philos  = atoi(argv[1]);
	table.time_to_die = atoi(argv[2]) * 1000;
	table.time_to_eat = atoi(argv[3]) * 1000;
	table.time_to_sleep = atoi(argv[4]) * 1000;
	table.philos = malloc(sizeof(t_philo) * table.num_philos);
	table.forks = malloc(sizeof(int) * table.num_philos);
	for(long i = 0; i < table.num_philos; i++)
	{
		table.forks[i] = 1;
		table.philos[i].pos = i+1;
		table.philos[i].table = &table;
		table.philos[i].time_last_eat = getTime();
		table.philos[i].num_must_eat = atoi(argv[5]);
	}
	for (long t = 0; t < table.num_philos; t++)
	{
		int rc = pthread_create(&table.philos[t].thread, NULL, &eat, &table.philos[t]);
		if (rc){
			printf("ERROR; return code from pthread_create () is %d\n", rc);
			exit(-1);
		}
	}
	for (long t = 0; t < table.num_philos; t++)
		pthread_join(table.philos[t].thread, NULL);
	pthread_mutex_unlock(&table.lock);
	pthread_exit (NULL);
}
