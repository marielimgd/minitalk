
#include "../includes/libft.h"
#include "../includes/minitalk.h"

int	send_message(int pid, char *str)
{
	static char	*message = NULL;
	static int	s_pid = 0;
	static int	bits = 0;

	if (str)
	{
		message = ft_strdup(str);
		if (!message)
			send_error(NULL, 0, 0);
	}
	if (pid)
		s_pid = pid;
	if (message[bits / BIT])
	{
		if (message[bits / BIT] & (1 << (7 - (bits % BIT))))
		{
			if (kill(s_pid, SIGUSR2) == SIG_ERROR)
				send_error(message, s_pid, SIGUSR2);
		}
		else if (kill(s_pid, SIGUSR1) == SIG_ERROR)
			send_error(message, s_pid, SIGUSR1);
		bits++;
		return (0);
	}
	if (!send_null(s_pid, message))
		return (0);
	free(message);
	message = NULL;
	return (1);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Error: Incorrect number of arguments!\n");
		ft_printf("Try: %s <PID> \"<MESSAGE>\"\n", argv[0]);
		exit(1);
	}
	signal(SIGUSR1, &handler_sig);
	signal(SIGUSR2, &handler_sig);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error: %s is an invalid PID\n", argv[1]);
		exit(1);
	}
	if (!argv[2] || !*argv[2])
	{
		ft_printf("Error: Message is empty\n");
		exit(1);
	}
	send_message(pid, argv[2]);
	while (1)
		pause();
}
