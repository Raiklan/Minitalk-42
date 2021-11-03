/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:40:10 by user42            #+#    #+#             */
/*   Updated: 2021/11/02 18:45:18 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <zconf.h>
#include "libft.h"
#include "minitalk.h"
#include <stdio.h>

void	usage(void)
{
	write(1, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

void	send_char(int server_pid, unsigned char byte)
{
	u_int8_t		counter;

	counter = 1 << 6;
	while (counter)
	{
		if (byte & counter)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error("Wrong server_pid\n");
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error("Wrong server_pid\n");
		}
		counter >>= 1;
		usleep(60);
	}
}

void	main_handler(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		++message;
	}
	send_char(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Message has been received, my man\n", 35);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		usage();
	signal(SIGUSR1, success);
	main_handler(argv[1], argv[2]);
	return (0);
}
