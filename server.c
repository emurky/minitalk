#include "minitalk.h"

void	print_1(int sig)
{
	if (sig == SIGUSR1)
		ft_putnbr(1);
}

void	print_0(int sig)
{
	if (sig == SIGUSR2)
		ft_putnbr(0);
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Hi from server, my PID is %d\n", pid);
	signal(SIGUSR1, print_1);
	signal(SIGUSR2, print_0);
	while (true)
	;
	
	return (0);
}
