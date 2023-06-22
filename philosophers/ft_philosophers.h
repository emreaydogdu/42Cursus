/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philosophers.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:18:56 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/21 23:31:31 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PHILOSOPHERS_H
# define FT_PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>

typedef struct s_table t_table;

typedef struct s_philo
{
	long			pos;
	pthread_t		thread;
	t_table			*table;
	unsigned int	time_last_eat;
	unsigned int	num_must_eat;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	int				*forks;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	int				num_philos;
	pthread_mutex_t	lock;
}	t_table;

#endif
