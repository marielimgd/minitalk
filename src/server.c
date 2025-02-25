/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:13 by marieli           #+#    #+#             */
/*   Updated: 2025/02/25 13:23:12 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	process_signal(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;
	static int				client_pid;

	(void)context;
	if (bit == 0)
		client_pid = info->si_pid;
	c |= (signal == SIGUSR1) << (7 - bit);
	bit++;
	// // Debugging: Print bit status and the current char being built
	// printf("Received signal: %s | Bit: %d | Current char: 0x%02x ('%c')\n",
	//        (signal == SIGUSR1) ? "SIGUSR1" : "SIGUSR2",
	//        bit, c, (c >= 32 && c <= 126) ? c : '.'); // Print printable chars only
	// fflush(stdout);  // Ensure logs are printed immediately
	if (bit == 8)
	{
		if (c == '\0')
		{
			write(1, "\n", 1);
			bit = 0; // Reset bit counter
		}
		else
			write(1, &c, 1);
		c = 0; // Reset character buffer
		bit = 0;
	}
	if (kill(client_pid, SIGUSR1) == -1) // Send acknowledgment back to client
	{
		write(1, "Error: Failed to send confirmation\n", 36);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = process_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
