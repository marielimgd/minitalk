/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:02 by marieli           #+#    #+#             */
/*   Updated: 2025/02/24 19:55:23 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile sig_atomic_t	g_received = 0;

void	confirm_bits(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
}

void	send_signal(int pid, unsigned char c)
{
	int	bit;

	bit = 8;
	while (bit-- > 0)
	{
		g_received = 0;
		if ((c >> bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_received)
			pause();
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
		return (1);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	c = 0;
	sa.sa_handler = confirm_bits;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	while (message[c])
	{
		send_signal(pid, message[c]);
		c++;
	}
	send_signal(pid, '\0');
	return (0);
}
