/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:04:54 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/15 15:43:15 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_server	g_server = {0, 0, 0};

void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_server.client_pid = info->si_pid;
	if (sig == SIGUSR1)
		g_server.c = (g_server.c << 1) | 0;
	else if (sig == SIGUSR2)
		g_server.c = (g_server.c << 1) | 1;
	g_server.bit_count++;
	if (g_server.bit_count == 8)
	{
		write(1, &g_server.c, 1);
		g_server.c = 0;
		g_server.bit_count = 0;
	}
	kill(g_server.client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_error("sigaction failed");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_error("sigaction failed");
	while (1)
		pause();
	return (0);
}
