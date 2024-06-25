/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:19:54 by emaydogd          #+#    #+#             */
/*   Updated: 2024/06/25 00:23:20 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../philosophers.h"

static int	ft_check_params(t_table *table, int argc, char *argv[])
{
	table->max_ate = 0;
	table->stop_condition = 0;
	table->count = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->eat_count_max = 0;
	if (argc == 6)
		table->eat_count_max = ft_atoi(argv[5]);
	if (table->count < 1 || table->time_to_die < 0 || table->time_to_eat < 0
		|| table->time_to_sleep < 0 || table->eat_count_max < 0)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_table	table;

	if (argc < 5 || argc > 6)
		return (ft_error(ERR_USAGE));
	if (!ft_check_params(&table, argc, argv))
		return (ft_error("Incorrect parameters.\n"));
	if (!ft_init(&table))
		return (ft_error("init error.\n"));
	if (!start_threads(&table))
		return (ft_error("threads error.\n"));
	return (0);
}
