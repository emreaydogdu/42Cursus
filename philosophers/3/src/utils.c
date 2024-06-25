/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:19:54 by emaydogd          #+#    #+#             */
/*   Updated: 2024/06/24 15:26:40 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

int	ft_error(char *msg) //
{
	write(2, msg, ft_strlen(msg));
	return (0);
}

int	ft_strlen(char *str) //
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * (unsigned long)1000) + (time.tv_usec / 1000));
}

void	new_sleep(unsigned long duration, t_table *env)
{
	unsigned long	start;

	start = get_time();
	while (!env->stop_condition)
	{
		if (get_time() - start >= duration)
			break ;
		usleep(env->count * 2);
	}
}
