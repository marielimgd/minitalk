#ifndef MINITALK_H
# define MINITALK_H

#include <signal.h> //for signal function
#include <stdio.h> //for printf
#include <stdlib.h> //for exit
#include <unistd.h> //for sleep
#include "libft.h"  // for ft_printf, ft_atoi


void	send_signal(int pid, unsigned char c);
void	process_signal (int signal);
void 	process_signal_back(int signal, siginfo_t *info, void *context);
void	confirm_bits(int signal);

#endif