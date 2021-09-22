#include "minitalk.h"

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	static int		ch = 0;
	static int		bits = 8;
	static char		buffer[BUFFER_SIZE + 1];
	static int		first_launch = false;
	static int		index = 0;

	if (!first_launch)
	{
		first_launch = true;
		ch = 0;
		index = 0;
		bits = 8;
		ft_bzero(buffer, sizeof(buffer));
	}
	
	if (bits)
	{
		if (sig == SIGUSR1)
		{
			ch |= 1 << (bits - 1);
			// ft_putchar('1');
			bits--;
		}
		else if (sig == SIGUSR2)
		{
			// ft_putchar('0');
			bits--;
		}
	}
	if (!bits)
	{

		buffer[index] = ch;
		index++;
		if (ch == '\0')
		{
			write(1, buffer, ft_strlen(buffer));
			first_launch = false;
			ft_putchar('\n');
		}
		// write(1, &ch, 1);
		ch = 0;
		bits = 8;

		if (index == BUFFER_SIZE)
		{
			write(1, buffer, BUFFER_SIZE);
			ft_bzero(buffer, sizeof(buffer));
			index = 0;
		}
	}
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr("Hi from server, my PID is ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();

	return (0);
}


			// ft_putstr("You can send a new message from another client, my PID is ");
			// ft_putnbr(getpid());
			// ft_putchar('\n');
