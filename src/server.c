
#include "../includes/libft.h"
#include "../includes/minitalk.h"

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

void	process_signal(int signum, siginfo_t *s_info, void *context)
{
	static char	c = 0;
	static int	bits = 0;
	static int	pid = 0;

	(void)context;

	pid = s_info->si_pid;
	
	if (signum == SIGUSR1)
		c |= (0 << (7 - bits));
	else if (signum == SIGUSR2)
		c |= (1 << (7 - bits));
	bits++;
	if (bits == BIT)
	{
		if (c)
			write(1, &c, 1);
		else
			write(1, "\n", 1);
		bits = 0;
		c = 0;
	}

	if (kill(pid, SIGUSR1) == SIG_ERROR)
	{
		kill(pid, SIGUSR2);
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	struct sigaction sa_sig;

	sigemptyset(&sa_sig.sa_mask);
	sigaddset(&sa_sig.sa_mask, SIGINT);
	sigaddset(&sa_sig.sa_mask, SIGQUIT);
	sa_sig.sa_handler = 0;
	sa_sig.sa_flags = SA_SIGINFO;
	sa_sig.sa_sigaction = process_signal;
	sigaction(SIGUSR1, &sa_sig, NULL);
	sigaction(SIGUSR2, &sa_sig, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
}