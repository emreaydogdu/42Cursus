/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:43:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/22 14:45:00 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <printf.h>

void	ft_output(int *c, int *bit, int *cpid, siginfo_t *info)
{
	if (*c == 0)
	{
		*cpid = 0;
		kill(info->si_pid, SIGUSR1);
	}
	else
		write(1, c, 1);
	*bit = 0;
	*c = 0;
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
	static int	cpid;

	(void)context;
	if (cpid == 0)
		cpid = info->si_pid;
	if (cpid == info->si_pid)
	{
		if (signal == SIGUSR1)
			c |= 1 << bit;
		if (++bit == 8)
			ft_output(&c, &bit, &cpid, info);
	}
	else
		kill(info->si_pid, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	ft_putpid(getpid(), 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = decode;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
