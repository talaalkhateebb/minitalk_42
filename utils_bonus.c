/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talkhati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 13:33:47 by talkhati          #+#    #+#             */
/*   Updated: 2026/01/14 13:41:33 by talkhati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	char	*c;

	c = "0123456789";
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &c[n % 10], 1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

void	ft_error(char *msg)
{
	ft_putstr("Error: ");
	ft_putstr(msg);
	write(1, "\n", 1);
	exit(1);
}
