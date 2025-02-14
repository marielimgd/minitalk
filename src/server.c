/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmariano <mmariano@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:13 by marieli           #+#    #+#             */
/*   Updated: 2025/02/14 15:52:08 by mmariano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void process_signal (int signal)
{
    static unsigned char    c; //guarda o valor do char recebido
    static int              bit; //guarda o index do bit

    // Set the current bit in 'c' based on the signal
    c |= (signal == SIGUSR1) << (7 - bit); //checka se o bit recebido é 0 ou 1 e performa | para cada bit
    bit++;
    
    // If 8 bits have been received, print c
    if (bit == 8) 
    {
        if (c == '\0') // End of message
            write(1, "\n", 1);
        else
            write(1, &c, 1);
        bit = 0;
        c = 0; // Reset for the next character        
    }    
}

int main(void)
{
    struct sigaction action;
    
    //setting the signal handles
    action.sa_handler = process_signal; //process  SIGUSR1 and SIGUSR2.
    action.sa_flags = SA_RESTART; //restart the system calls after the interruption by the signals
    sigemptyset(&action.sa_mask); //ensure no signals are blocked during handler execution

    // Register the signal handler for SIGUSR1 and SIGUSR2
    sigaction(SIGUSR1, &action, NULL);
    sigaction(SIGUSR2, &action, NULL);
    
    //print the PID
    ft_printf("%d\n", getpid());
    
    //wait for the signal
    while(1)
        pause();
    return(0);
}
