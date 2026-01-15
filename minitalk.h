/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 19:04:02 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/14 13:38:11 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>

typedef struct s_server
{
	unsigned char	c;
	int				bit_count;
	pid_t			client_pid;
}	t_server;
void	signal_handler(int sig, siginfo_t *info, void *context);
void	send_char(int pid, char c);
void	send_message(int pid, char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		ft_atoi(const char *str);
void	ft_error(char *msg);

#endif
