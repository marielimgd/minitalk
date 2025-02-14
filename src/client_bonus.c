/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:02 by marieli           #+#    #+#             */
/*   Updated: 2025/02/14 17:34:58 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

// Signal handler for confirmation
void confirm_bits(int signal)
{
    if (signal == SIGUSR1)
        write(1, "Received bit 1\n", 15); // Server acknowledged a '1' bit
    else if (signal == SIGUSR2)
        write(1, "Received bit 0\n", 15); // Server acknowledged a '0' bit
}

// Function to send a character bit by bit
void send_signal(int pid, unsigned char c)
{
    int 		bit;
	sigset_t 	mask;
	sigset_t	 oldmask;

	sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    sigprocmask(SIG_BLOCK, &mask, &oldmask);

    bit = 8;
    while (bit > 0)
    {
        bit--;
        if ((c >> bit) & 1) // Extract the current bit from MSB to LSB
            kill(pid, SIGUSR1); // Send SIGUSR1 if bit = 1
        else
            kill(pid, SIGUSR2); // Send SIGUSR2 if bit = 0
        usleep(100); // Small delay to ensure signals are processed in order

        // Atomically unblock signals and wait for ACK
        sigsuspend(&oldmask);
    }

    // Restore original signal mask
    sigprocmask(SIG_SETMASK, &oldmask, NULL);
}

int main(int argc, char **argv)
{
    int pid;
    const char *message;
    int c;

    // Check command-line arguments
    if (argc != 3)
    {
        write(1, "Usage: ./client_bonus <pid> <message>\n", 38);
        exit(0);
    }

    // Parse server PID and message
    pid = ft_atoi(argv[1]);
    message = argv[2];

    // Set up the confirmation signal handler
    struct sigaction sa;
    sa.sa_handler = confirm_bits;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    // Send each character of the message
    c = 0;
    while (message[c])
    {
        send_signal(pid, message[c]);
        c++;
    }

    // Send null terminator to indicate end of message
    send_signal(pid, '\0');

    return 0;
}