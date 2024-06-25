/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:06:45 by sgoffaux          #+#    #+#             */
/*   Updated: 2024/06/25 14:13:01 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>

# define ERR_USAGE "Please: ./philo <# philosophers> <time to die> <time to eat>\
 <time to sleep> [# times each philosopher must eat]\n"
# define UNLOCK 1
# define LOCK 0

struct	s_env;

typedef struct s_philo
{
	int				ate_times;
	int				pos;
	char			*pos_str;
	int				ffork;
	int				sfork;
	unsigned long	last_ate;
	struct s_table	*table;
	pthread_t		thread_id;
}				t_philo;

typedef struct s_table
{
	int				count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_count_max;
	unsigned long	start_time;
	int				stop_condition;
	int				max_ate;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	writing;
}				t_table;

int				ft_error(char *msg);

int				ft_atoi(const char *nptr);
int				ft_strlen(char *str);
char			*ft_itoa(int nbr);
int				ft_init(t_table *env);
void			philo_print(char *msg, t_philo *philo, int unlock);
void			philo_eat(t_philo *philo);
void			philo_dead(t_table *env, t_philo *philo);
int				start_threads(t_table *env);
unsigned long	get_time(void);
void			new_sleep(unsigned long duration, t_table *env);

#endif