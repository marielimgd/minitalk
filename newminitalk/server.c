/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marieli <marieli@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 19:54:13 by marieli           #+#    #+#             */
/*   Updated: 2025/02/13 21:02:44 by marieli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void process_signal (int signal)
{
    static unsigned char    letter; //guarda o valor do char recebido
    static int              bit; //guarda o index do bit

    // letter |= (signal == SIGUSR1); // checka se o bit recebido é 0 ou 1
    letter = (letter << 1) | (signal == SIGUSR1); //if signal is SIGUSR1, LSB = 1, if signal is not SIGUSR1, LSB = 0
    bit++;
    if (bit == 8) // If 8 bits received, form a full character
    {
        if (letter == '\0')
            write(1, "\n", 1);
        else
            write(1,&letter,1);
        bit = 0;
        letter = 0; // Reset for the next character        
    }    
}

int main(void)
{

    // struct sigaction sa;
    // sa.sa_handler = process_signal;
    // sa.sa_flags = SA_RESTART;
    // sigaction(SIGUSR1, &sa, NULL);
    // sigaction(SIGUSR2, &sa, NULL);
    
    signal(SIGUSR1, process_signal);
    signal(SIGUSR2, process_signal);
    printf("%d\n", getpid());
    while(1)
        pause();
    return(0);
}
