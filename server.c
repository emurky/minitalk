#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	static int		ch = 0;
	static int		bits = 8;
	static char		buffer[BUFFER_SIZE + 1];
	// static int		index;

	ft_bzero(buffer, sizeof(char));
	if (bits)
	{
		if (sig == SIGUSR1)
		{
			ch |= 1 << (bits - 1);
			bits--;
		}
		else if (sig == SIGUSR2)
		{
			bits--;
		}
	}
	if (!bits)
	{
		if (ch == '\0')
		{
		// should uncomment this for buffer handling
			// write(1, buffer, ft_strlen(buffer));
			ft_putchar('\n');
			// ft_putstr("You can send a new message from another client, my PID is ");
			// ft_putnbr(getpid());
			// ft_putchar('\n');
		}

	// should uncomment this for buffer handling
		// buffer[index] = ch;	
		// index++;	

		write(1, &ch, 1);
		ch = 0;
		bits = 8;
	}

// should uncomment this for buffer handling
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
