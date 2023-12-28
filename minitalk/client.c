/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:23:09 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/22 14:59:10 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

int	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	acknowledge(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Message acknowledged\n", 21);
	else if (signal == SIGUSR2)
		write(1, "Server is busy\n", 15);
	exit(0);
}

void	send(int pid, char *msg)
{
	int	bit;

	while (*msg)
	{
		bit = 0;
		while (bit < 8)
		{
			if (*msg >> bit++ & 1)
			{
				if (kill(pid, SIGUSR1) == -1)
					ft_error();
			}
			else if (kill(pid, SIGUSR2) == -1)
				ft_error();
			usleep(150);
		}
		msg++;
	}
	while (bit--)
	{
		if (kill(pid, SIGUSR2) == -1)
			ft_error();
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 3)
		ft_error();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_handler = acknowledge;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send(ft_atoi(argv[1]), argv[2]);
	pause();
}
