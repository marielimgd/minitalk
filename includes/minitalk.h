#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h> //for signal function
#include <stdio.h> //for printf
#include <stdlib.h> //for exit
#include <unistd.h> //for sleep
#include <string.h> //for  pid_t
#include "libft.h"  // for ft_printf, ft_atoi


void send_signal(int pid, unsigned char c);
void process_signal (int signal);

#endif