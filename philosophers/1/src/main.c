/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhagiwar <hhagiwar@student.42Tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:36:39 by hhagiwar          #+#    #+#             */
/*   Updated: 2023/09/24 16:28:36 by hhagiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philosophers.h"

void	case_one_philo(t_info *info)
{
	usleep(info->time_to_die * 1000);
	print(&info->philos[0], "died");
	clear_data(info);
}

void	clear_data(t_info *info)
{
	if (info->th)
		free(info->th);
	if (info->forks)
		free(info->forks);
	if (info->philos)
		free(info->philos);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (error_check(argc, argv) == ERROR)
		return (printf(ERROR_MSG), 1);
	if (init_philo(&info, argc, argv) == ERROR)
		return (printf(ERROR_MSG), 1);
	info.philos = set_philosopher(info.philo_num, info);
	if (info.philos == NULL)
		return (printf(ERROR_MSG), 1);
	if (info.philo_num == 1)
		case_one_philo(&info);
	else
		exec_philosophers(info);
	return (0);
}
