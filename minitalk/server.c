/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:43:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/09 16:22:11 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_putpid(int pid, int p)
{
	unsigned char	c;

	if (p)
		write(1, "PID: ", 5);
	if (pid > 9)
		ft_putpid(pid / 10, 0);
	c = pid % 10 + '0';
	write(1, &c, 1);
	if (p)
		write(1, "\n", 1);
}

void	decode(int signal, siginfo_t *info, void *context)
{
	static int	c;
	static int	bit;

	(void)context;
	if (signal == SIGUSR1)
		c |= 1 << bit;
	bit++;
	if (bit == 8)
	{
		if (c == 0)
		{
			if (kill(info->si_pid, SIGUSR1) == -1)
				ft_error();
		}
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		ft_error();
	ft_putpid(getpid(), 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = decode;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
	return (0);
}
