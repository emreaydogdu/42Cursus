/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:23:09 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/06 23:10:05 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <printf.h>
#include <stdlib.h>

void	acknowledge(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Message acknowledged\n", 21);
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
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		msg++;
	}
	while (bit--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}
	signal(SIGUSR2, acknowledge);
	send(atoi(argv[1]), argv[2]);
	pause();
}
