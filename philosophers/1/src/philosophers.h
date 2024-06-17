/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:36:54 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/09/25 22:13:45 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR 1

# define TRUE 1
# define FALSE 0

# define ERROR_MSG "Error\n"

struct	s_info;

typedef struct s_philo
{
	struct s_info	*info;
	pthread_t		t1;
	int				id;
	int				eat_count;
	int				eating;
	int				finish_flag;
	u_int64_t		last_meal_time;
	pthread_mutex_t	dead_mutex;
}					t_philo;

typedef struct s_info
{
	pthread_t		*th;
	int				philo_num;
	int				must_eat;
	int				dead;
	int				finish_count;
	t_philo			*philos;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	u_int64_t		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	finish_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	write;
}					t_info;

// action
void				eat(t_philo *philo);
void				think(t_philo *philo);
void				*monitor(void *info_ptr);
void				exec_philosophers(t_info info);
void				sleep_philo(t_philo *philo);

// set
int					init_philo(t_info *info, int argc, char **argv);
t_philo				*set_philosopher(int num, t_info info);
void				set_fork(t_info info);

// print
void				print(t_philo *philo, char *action);
void				error_output(void);

// utils
unsigned long		get_time(void);
void				clear_data(t_info *info);
int					check_finish(t_philo philo);
void				pick_up_forks(t_philo *philo);
void				put_down_forks(t_philo *philo);
int					monitor_count(t_philo *philo);
int					monitor_finish(t_philo philo);

// othres
int					error_check(int argc, char **argv);
int					ft_atoi(const char *str);

#endif