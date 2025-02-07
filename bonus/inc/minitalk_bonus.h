#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include "libft.h"

# define BIT 8
# define SIG_ERROR -1

void	send_error(char *message, int pid, int sig);
void	handler_sig(int sig);
int		send_message(int pid, char *str);
int		send_null(int pid, char *message);

#endif