/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:02 by marieli           #+#    #+#             */
/*   Updated: 2025/02/25 13:52:26 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile sig_atomic_t	g_received = 0;

void	confirm_bits(int signal)
{
	if (signal == SIGUSR1)
		g_received = 1;
}

void send_signal(int pid, unsigned char c)
{
    int current_bit;
    int bit_position;
    sigset_t mask;
    sigset_t old_mask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, &old_mask);

    bit_position = 8;
    while (bit_position-- > 0)
    {
        g_received = 0;
        current_bit = (c >> bit_position) & 1;  // Extract bit at 'bit_position'
        if (current_bit)
            kill(pid, SIGUSR1);  // Send SIGUSR1 for 1-bit
        else
            kill(pid, SIGUSR2);  // Send SIGUSR2 for 0-bit
        usleep(1000);
        while (!g_received)
            sigsuspend(&old_mask);
    }
    sigprocmask(SIG_SETMASK, &old_mask, NULL);
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
