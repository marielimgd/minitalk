
#include "../includes/libft.h"
#include "../includes/minitalk.h"

void	send_error(char *message, int pid, int sig)
{
	if (pid > 0)
	{
		if (sig == SIGUSR1)
			ft_printf("Error: Sending SIGUSR1 signal to PID %i failed\n", pid);
		else if (sig == SIGUSR2)
			ft_printf("Error: Sending SIGUSR2 signal to PID %i failed\n", pid);
		else
			ft_printf("Error: Sending unknown signal to PID %i\n", pid);
	}
	else
		ft_printf("Error: Invalid PID\n");
	if (message)
		free(message);
	exit(EXIT_FAILURE);
}

int	send_null(int pid, char *message)
{
	static int	index = 0;

	if (index++ < BIT)
	{
		if (kill(pid, SIGUSR1) == SIG_ERROR)
			send_error(message, pid, SIGUSR1);
		return (0);
	}
	return (1);
}

void	handler_sig(int sig)
{
	if (sig == SIGUSR1)
	{
		if (send_message(0, NULL))
			write(1, "Info: Message received successfully.\n", 36);
	}
	else if (sig == SIGUSR2)
	{
		write(1, "Error: Server ended unexpectedly.\n", 34);
		exit(EXIT_FAILURE);
	}
}
