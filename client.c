#include "minitalk.h"

// #include <stdio.h>


void	my_exit(int status, char *exit_str)
{
	ft_putendl_fd(exit_str, 1);
	exit(status);
}

int	str_isdigit(char *str)
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
		if (kill(server_pid, SIGUSR2) < 0)
			my_exit(EXIT_FAILURE, ERR_SENDSIG);
		bits--;
	}
	if (!bits)
		my_exit(EXIT_SUCCESS, "Message was successfully sent");
}

void	send_message(char *str, pid_t pid)
{
	static char		*message;
	static int		bits = 8;
	static int		server_pid;

	if (str)
		message = str;
	if (pid)
		server_pid = pid;
	if (!bits)
	{
		message++;
		bits = 8;
	}
	if (!(*message))
		send_null(server_pid);
	if (*message && (*message & (1 << (bits - 1))))
	{
		if (kill(server_pid, SIGUSR1) < 0)
			my_exit(EXIT_FAILURE, ERR_SENDSIG);
	}
	else if (*message && kill(server_pid, SIGUSR2) < 0)
		my_exit(EXIT_FAILURE, ERR_SENDSIG);
	bits--;
}

void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	(void)siginfo;
	if (sig == SIGUSR1)
		send_message(NULL, 0);
	else if (sig == SIGUSR2)
		my_exit(EXIT_FAILURE, ERR_FROM_SERV);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (!(argc == 3 && str_isdigit(argv[1])))
		my_exit(EXIT_FAILURE, ERR_WRARG);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) || sigaction(SIGUSR2, &sa, NULL))
		my_exit(EXIT_FAILURE, ERR_SIGACT);
	send_message(argv[2], ft_atoi(argv[1]));
	while (true)
		pause();
	return (0);
}
