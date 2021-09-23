#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdbool.h>

# define BUFFER_SIZE	1024

# define ERR_WRARG		"Wrong arguments\nShould be \"./client PID message\""
# define ERR_SERV		"Could not connect with server"
# define ERR_FROM_SERV	"Error was sent from server"
# define ERR_SENDSIG	"Could not send a signal"
# define ERR_SIGACT		"sigaction() returned error"



#endif
