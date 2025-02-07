#ifndef MINITALK_H
# define MINITALK_H

#include <unistd.h> // For write, getpid, pause, usleep
#include <signal.h> // For signal, sigaction, kill
#include <stdlib.h> // For malloc, free, exit
#include <stdio.h>  // For printf (debugging only, avoid in signal handlers)
#include "libft.h"  // Assuming you're using your custom libft for ft_printf, ft_atoi

# define BIT 8
# define SIG_ERROR -1
# define DELAY 100

void    send_error(char *message, int pid, int sig);
int     send_null(int pid, char *message);
int     send_message(int pid, char *str);
void    handler_sig(int sig);
void    signal_handler(int signum, siginfo_t *s_info, void *context);

#endif