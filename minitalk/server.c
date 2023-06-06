/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:43:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/06 23:09:52 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <printf.h>

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
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
	{
		printf("Error\n");
		return (1);
	}
	pid = getpid();
	printf("PID: %d\n", pid);
	sa.sa_sigaction = decode;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	while (1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
}
