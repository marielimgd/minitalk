/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:13 by marieli           #+#    #+#             */
/*   Updated: 2025/02/17 15:28:37 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	process_signal_back(int signal, siginfo_t *info, void *context)
{
	static unsigned char	c;
	static int				bit;
	static int				client_pid;

	(void)context;
	if (bit == 0)
		client_pid = info->si_pid;
	c |= (signal == SIGUSR1) << (7 - bit);
	bit++;
	if (kill(client_pid, signal) == -1)
	{
		write(1, "Error: Failed to send confirmation\n", 36);
		exit(EXIT_FAILURE);
	}
	if (bit == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = process_signal_back;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("%d\n", getpid());
	while (1)
		pause();
	return (0);
}
