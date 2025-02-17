/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:02 by marieli           #+#    #+#             */
/*   Updated: 2025/02/17 15:29:01 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	confirm_bits(int signal)
{
	if (signal == SIGUSR1)
		write(1, "Received bit 1\n", 15);
	else if (signal == SIGUSR2)
		write(1, "Received bit 0\n", 15);
}

void	send_signal(int pid, unsigned char c)
{
	int			bit;
	sigset_t	mask;

	sigemptyset(&mask);
	sigaddset(&mask, SIGUSR1);
	sigaddset(&mask, SIGUSR2);
	bit = 8;
	while (bit > 0)
	{
		bit--;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		sigsuspend(&mask);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	const char			*message;
	int					c;
	struct sigaction	sa;

	if (argc != 3)
	{
		write(1, "Usage: ./client <pid> <message>\n", 33);
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	c = 0;
	sa.sa_handler = confirm_bits;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (message[c])
	{
		send_signal(pid, message[c]);
		c++;
	}
	send_signal(pid, '\0');
	return (0);
}
