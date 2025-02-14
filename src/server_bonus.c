/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:13 by marieli           #+#    #+#             */
/*   Updated: 2025/02/14 17:24:42 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void process_signal_back(int signal, siginfo_t *info, void *context)
{
    static unsigned char c; // Stores the reconstructed character
    static int bit;         // Tracks the current bit position (0 to 7)
    static int client_pid;  // Stores the client's PID

    (void)context;

    // Store the client's PID on the first signal
    if (bit == 0)
        client_pid = info->si_pid;

    // Set the current bit in 'c' based on the signal
    c |= (signal == SIGUSR1) << (7 - bit);
    bit++;

    // Send acknowledgment signal to the client
    if (kill(client_pid, signal) == -1) // Send the same signal back
    {
        write(1, "Error: Failed to send confirmation\n", 36);
        exit(EXIT_FAILURE);
    }

    // If 8 bits have been received, print the character
    if (bit == 8)
    {
        if (c == '\0') // End of message
            write(1, "\n", 1);
        else // Print the character
            write(1, &c, 1);

        bit = 0; // Reset for the next character
        c = 0;   // Reset for the next character
    }
}

int main(void)
{
    struct sigaction sa;

    // Set up the signal handler
    sa.sa_sigaction = process_signal_back;
    sa.sa_flags = SA_SIGINFO; // Use sa_sigaction instead of sa_handler
    sigemptyset(&sa.sa_mask);

    // Register the signal handler for SIGUSR1 and SIGUSR2
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    // Print the server's PID
    printf("%d\n", getpid());

    // Wait indefinitely for signals
    while (1)
        pause();

    return 0;
}