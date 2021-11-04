/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 16:40:39 by user42            #+#    #+#             */
/*   Updated: 2021/11/04 17:27:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minitalk.h"

void	usage(void)
{
	write(1, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

void	send_char(int pid, unsigned char byte)
{
	u_int8_t		mask;

	mask = 1 << 6;
	while (mask)
	{
		if (byte & mask)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("Wrong server pid\n");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("Wrong server pid\n");
		}
		mask >>= 1;
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
	write(1, "Message received.\n", 19);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		usage();
	if (argv[1])
	{
		while (argv[1][i] != '\0')
		{
			if (ft_isdigit(argv[1][i]) == 0)
				error("PID must be a number\n");
			i++;
		}
	}
	signal(SIGUSR1, success);
	main_handler(argv[1], argv[2]);
	return (0);
}
