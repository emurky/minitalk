/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emurky <emurky@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 02:30:31 by emurky            #+#    #+#             */
/*   Updated: 2021/09/24 02:30:40 by emurky           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft.h"
# include <signal.h>
# include <stdbool.h>

# define BUFFER_SIZE	1024

# define ERR_WRARG		"Wrong arguments\nShould be \"./client PID message\""
# define ERR_PID		"Server PID should be numerical"
# define ERR_SERV		"Could not connect with server"
# define ERR_FROM_SERV	"Error was sent from server"
# define ERR_SENDSIG	"Could not send a signal"
# define ERR_SIGACT		"sigaction() returned error"

#endif
