#include "minitalk.h"

#include <stdio.h>


void	my_exit(int status, char *exit_str)
{
	ft_putendl_fd(exit_str, 1);
	exit(status);
}

int	string_isdigit(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

void	send_null(pid_t server_pid)
{
	static int		bits = 8;

	if (bits)
	{
		kill(server_pid, SIGUSR2);
		bits--;
	}
	if (!bits)
	{
		my_exit(EXIT_SUCCESS, "Message was successfully sent");
	}
}

void	send_message(char *str, pid_t pid)
{
	static char		*message;
	static int		bits = 8;
	static int		server_pid;

	if (str) {
		message = str; }
	if (pid)
		server_pid = pid;

	if (!bits)
	{
		message++;
		// printf("%s\n", message);
		bits = 8;
	}

	if (*message)
	{
		// if (bits)
		// {
			if (*message & (1 << (bits - 1)))
			{
				if (kill(server_pid, SIGUSR1) < 0)
					my_exit(EXIT_FAILURE, ERR_SIG);
				// ft_putchar('1');
				// printf("%d bits\n", bits);
				// usleep(50);
			}
			else
			{
				if (kill(server_pid, SIGUSR2) < 0)
					my_exit(EXIT_FAILURE, ERR_SIG);
				// ft_putchar('0');
				// printf("%d bits\n", bits);
				// usleep(50);
			}
			bits--;
		// }
		// if (!bits)
		// {
		// 	message++;
		// 	// printf("%s\n", message);
		// 	bits = 8;
		// }
	}
	else
	{
		send_null(server_pid);
		// kill(server_pid, SIGUSR2);
		// usleep(50);
		// bits--;
	}
	// printf("%d bits\n", bits);
}

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (sig == SIGUSR1)
		send_message(NULL, 0);
	// else if (sig == SIGUSR2)
	// 	exit(0);
}

int	main(int argc, char **argv)
{
	char			*message;
	pid_t			server_pid;
	struct sigaction	sa;

	if (!(argc == 3 && string_isdigit(argv[1])))
		my_exit(EXIT_FAILURE, ERR_WRARG);

	server_pid = ft_atoi(argv[1]);
	message = argv[2];

	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_message(argv[2], server_pid);

	// ft_putstr_fd("Hi from client, my PID is ", 1);
	// ft_putnbr_fd(getpid(), 1);
	// ft_putchar_fd('\n', 1);
	while (true)
		pause();
	return (0);
}
