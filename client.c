#include "minitalk.h"

void	my_exit(int status, char *exit_str)
{
	ft_putendl(exit_str);
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

int	main(int argc, char **argv)
{
	char				*message;
	pid_t				server_pid;
	int					bits = CHAR_SIZE;


	if (!(argc == 3 && string_isdigit(argv[1])))
		my_exit(EXIT_FAILURE, ERR_WRARG);

	server_pid = ft_atoi(argv[1]);
	message = argv[2];


	while (*message)
	{
		bits = CHAR_SIZE;
		while (bits)
		{
			if (*message & bits) {
				kill(server_pid, SIGUSR1);
				usleep(50);
			}
			else {
				kill(server_pid, SIGUSR2);
				usleep(50);
			}
			bits >>= 1;
		}
		message++;
	}
	bits = CHAR_SIZE;
	while (bits)
	{
		kill(server_pid, SIGUSR2);
		usleep(50);
		bits >>= 1;
	}

	ft_printf("Hi from client, my PID is %d\n", getpid());

	return (0);
}
