/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:02 by marieli           #+#    #+#             */
/*   Updated: 2025/02/17 16:37:47 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void confirm_bits(int signal) {
    if (signal == SIGUSR1)
        write(1, "Received bit 1\n", 15);
    else if (signal == SIGUSR2)
        write(1, "Received bit 0\n", 15);
}

void send_signal(int pid, unsigned char c) 
{
    int bit;
    sigset_t mask, oldmask;

    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR1);
    sigaddset(&mask, SIGUSR2);
    sigprocmask(SIG_BLOCK, &mask, &oldmask);
    bit = 8;
    while (bit-- > 0) {
        if ((c >> bit) & 1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        usleep(100);
        sigsuspend(&oldmask);
    }
    sigprocmask(SIG_SETMASK, &oldmask, NULL);
}

int main(int argc, char **argv)
{
    int pid;
    const char *message;
    int c;

    if (argc != 3)
    {
        write(1, "Usage: ./client_bonus <pid> <message>\n", 38);
        exit(0);
    }
    pid = ft_atoi(argv[1]);
    message = argv[2];
    struct sigaction sa;
    sa.sa_handler = confirm_bits;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    c = 0;
    while (message[c])
    {
        send_signal(pid, message[c]);
        c++;
    }
    send_signal(pid, '\0');
    return (0);
}