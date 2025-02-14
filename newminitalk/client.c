/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:02 by marieli           #+#    #+#             */
/*   Updated: 2025/02/13 21:03:28 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <string.h>

void send_signal(int pid, unsigned char c)
{
	int bit;

	bit = 8;
	while (bit > 0)
	{
		bit--;
		if ((c >> bit) & 1) // extract the curent bit
			kill(pid, SIGUSR1); // Send SIGUSR1 if bit = 1
		else
			kill(pid, SIGUSR2); // Send SIGUSR2 if bit = 0
		usleep(100);
	}
}

int main(int argc, char **argv)
{	
	int			pid;
	const char	*message;
	int			index;

	if (argc != 3)
	{
		printf("Usage: %s <pid> <message>\n", argv[0]);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	index = 0;
	while(message[index])
		send_signal(pid, message[index++]);
	send_signal(pid, '\0');
	return(0);
}
