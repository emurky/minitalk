#include "minitalk.h"

// #include <fcntl.h>
// #include <stdio.h>
int	fd = 1;

void	my_exit(int status, char *exit_str, pid_t client_pid)
{
	ft_putendl_fd(exit_str, 1);
	if (status == EXIT_FAILURE && client_pid)
		kill(client_pid, SIGUSR2);
	exit(status);
}

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int		client_pid = 0;
	static char		ch = 0;
	static int		bits = 8;
	static char		buffer[BUFFER_SIZE + 1];
	static int		index = 0;
	static int		first_launch = false;

	(void)context;
	if (!first_launch)
	{
		first_launch = true;
		index = 0;
		client_pid = siginfo->si_pid;
		ft_bzero(buffer, sizeof(buffer));
	}
	if (sig == SIGUSR1)
		ch |= 1 << (bits - 1);
	bits--;
	if (!bits)
	{
		bits = 8;
		if (ch == '\0')
		{
			write(fd, buffer, ft_strlen(buffer));
			first_launch = false;
			ft_putchar_fd('\n', fd);
			return ;
		}
		else
			buffer[index++] = ch;
		ch = 0;
		if (index == BUFFER_SIZE)
		{
			write(fd, buffer, BUFFER_SIZE);
			ft_bzero(buffer, sizeof(buffer));
			index = 0;
		}
	}
	if (kill(client_pid, SIGUSR1) < 0)
		my_exit(EXIT_FAILURE, ERR_SENDSIG, client_pid);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

// int fdd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC);
// fd = fdd;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("Hi from server, my PID is ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		my_exit(EXIT_FAILURE, ERR_SIGACT, 0);
	while (true)
		pause();
	return (0);
}
