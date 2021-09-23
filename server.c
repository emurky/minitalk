#include "minitalk.h"

#include <fcntl.h>
#include <stdio.h>
int	fd = 1;



void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	(void)context;
	static char		ch = 0;
	static int		bits = 8;
	static int		client_pid = 0;
	static char		buffer[BUFFER_SIZE + 1];
	static int		first_launch = false;
	static int		index = 0;

	if (!first_launch)
	{
		first_launch = true;
		// ch = 0;
		index = 0;
		client_pid = siginfo->si_pid;
		// bits = 8;
		ft_bzero(buffer, sizeof(buffer));
	}
	
	if (!client_pid)
	{
		client_pid = siginfo->si_pid;
	}

	// printf("%d bits 1\n", bits);
	// if (bits)
	// {
		if (sig == SIGUSR1)
		{
			ch |= 1 << (bits - 1);
			// ft_putchar('1');
			// bits--;
		}
		else if (sig == SIGUSR2)
		{
			// ft_putchar('0');
			// bits--;
		}
		bits--;
	// }
	// printf("%d bits 2\n", bits);
	if (!bits)
	{
		bits = 8;
		if (ch == '\0')
		{
			write(fd, buffer, ft_strlen(buffer));
			// printf("%s i %zu strlen\n", buffer, ft_strlen(buffer));
			// printf("tut\n");
			first_launch = false;

			// kill(client_pid, SIGUSR2);
			// client_pid = 0;
			ft_putchar_fd('\n', fd);
			return ;
			// printf("%d char\n%d index\n%d bits\n%d first launch\n", ch, index, bits, first_launch);
		}
		else
		{
			buffer[index] = ch;
			index++;
		}

		// write(1, &ch, 1);

		ch = 0;

		if (index == BUFFER_SIZE)
		{
			write(fd, buffer, BUFFER_SIZE);
			ft_bzero(buffer, sizeof(buffer));
			index = 0;
		}
	}
	// printf("%d bits 3\n", bits);
	// printf("%d index\n", index);
	// if (first_launch == false)
		// kill(siginfo->si_pid, SIGUSR2);
	kill(client_pid, SIGUSR1);
	// printf("%d char\n%d index\n%d bits\n%d first launch\n", ch, index, bits, first_launch);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

int fdd = open("test.txt", O_RDWR | O_CREAT | O_TRUNC);
fd = fdd;
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	pid = getpid();
	ft_putstr_fd("Hi from server, my PID is ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (true)
		pause();

	return (0);
}


			// ft_putstr("You can send a new message from another client, my PID is ");
			// ft_putnbr(getpid());
			// ft_putchar('\n');
