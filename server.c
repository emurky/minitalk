#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	static int		ch = 0;
	static int		bits = 1;
	static char		buffer[BUFFER_SIZE + 1];
	// static int		index;

	ft_bzero(buffer, sizeof(char));
	if (bits <= 8)
	{
		if (sig == SIGUSR1)
		{
			ch |= 1 << (8 - bits);
			bits++;
		}
		else if (sig == SIGUSR2)
		{
			bits++;
		}
	}
	if (bits > 8)
	{
		if (ch == '\0')
		{
			// write(1, buffer, ft_strlen(buffer));
			ft_putchar('\n');
		}

		// write(1, "tut", 3);
		// buffer[index] = ch;
		// index++;

		write(1, &ch, 1);
		ch = 0;
		bits = 1;
	}
	// if (index == BUFFER_SIZE)
	// {
	// 	write(1, buffer, BUFFER_SIZE);
	// 	ft_bzero(buffer, sizeof(char));
	// 	index = 0;
	// }

}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_printf("Hi from server, my PID is %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();

	return (0);
}
