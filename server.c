/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:23:18 by emurky            #+#    #+#             */
/*   Updated: 2021/09/24 02:30:10 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	my_exit(int status, char *exit_str, pid_t client_pid)
{
	ft_putendl_fd(exit_str, 1);
	if (status == EXIT_FAILURE && client_pid)
		kill(client_pid, SIGUSR2);
	exit(status);
}

static int	buffer_handler(char *buffer, int *index, int *client_pid)
{
	if (buffer[*index] == '\0')
	{
		write(1, buffer, ft_strlen(buffer));
		*client_pid = 0;
		ft_putchar_fd('\n', 1);
		return (1);
	}
	else
		(*index)++;
	if (*index == BUFFER_SIZE)
	{
		write(1, buffer, BUFFER_SIZE);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		*index = 0;
	}
	return (0);
}

static void	signal_handler(int sig, siginfo_t *siginfo, void *context)
{
	static int		client_pid = 0;
	static int		bits = 8;
	static char		buffer[BUFFER_SIZE + 1];
	static int		index = 0;

	(void)context;
	if (!client_pid)
	{
		index = 0;
		client_pid = siginfo->si_pid;
		ft_bzero(buffer, BUFFER_SIZE + 1);
	}
	if (sig == SIGUSR1)
		buffer[index] |= 1 << (bits - 1);
	bits--;
	if (!bits)
	{
		bits = 8;
		if (buffer_handler(buffer, &index, &client_pid))
			return ;
	}
	if (kill(client_pid, SIGUSR1) < 0)
		my_exit(EXIT_FAILURE, ERR_SENDSIG, client_pid);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

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
