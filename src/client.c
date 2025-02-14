/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:02 by marieli           #+#    #+#             */
/*   Updated: 2025/02/14 15:52:00 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void send_signal(int pid, unsigned char c)
{
	int bit;

	bit = 8;
	while (bit > 0)
	{
		bit--;
		if ((c >> bit) & 1) // extract the curent bit from MSB to LSB
			kill(pid, SIGUSR1); // Send SIGUSR1 if bit = 1
		else
			kill(pid, SIGUSR2); // Send SIGUSR2 if bit = 0
		usleep(42);
	}
}

int main(int argc, char **argv)
{	
	int			pid;
	const char	*message;
	int			c;

	if (argc != 3)
	{
		ft_printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}

	// Parse server PID and message
	pid = ft_atoi(argv[1]);
	message = argv[2];
	c = 0;
	while(message[c])
		send_signal(pid, message[c++]);
	send_signal(pid, '\0');
	return(0);
}
