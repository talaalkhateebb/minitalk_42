/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:04:37 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/15 15:42:42 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack = 0;

void	ack_handler(int sig)
{
	(void)sig;
	g_ack = 1;
	//write(1, "well done", 10);
}

void	send_char(int pid, char c)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		g_ack = 0;
		if ((c >> bit) & 1)
		{
			if (kill(pid, SIGUSR2) == -1)
				ft_error("kill failed");
		}
		else
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("kill failed");
		}
		while (!g_ack)
			pause();
		bit--;
	}
}

void	send_message(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		send_char(pid, str[i]);
		i++;
	}
	write(1, "well done", 10);
	send_char(pid, '\n');
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr("Usage: ./client <PID> <message>\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		ft_error("Invalid PID");
	signal(SIGUSR1, ack_handler);
	send_message(pid, argv[2]);
	return (0);
}
