/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 22:28:20 by saich             #+#    #+#             */
/*   Updated: 2021/11/04 22:52:57 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/include.h"

int	g_received;

static int	wait_sig(void)
{
	while (g_received == 0)
		usleep(10);
	if (g_received == 1)
		g_received = 0;
	return (1);
}

static void	handler(int signum)
{
	(void)signum;
	ft_putstr_fd("signal received\n", 1);
	g_received = 1;
}

static void	send_zero(pid_t pid, char *send)
{
	int	i;

	i = 0;
	while (ft_strlen(send) + i < 7)
	{
		kill(pid, SIGUSR2);
		wait_sig();
		i++;
	}
}

static int	send_ascii(pid_t pid, char c)
{
	char	*tmp;
	char	*send;
	int		i;

	tmp = ft_itoa(c);
	send = ft_convert_base(tmp, "0123456789", "01");
	free(tmp);
	i = 0;
	send_zero(pid, send);
	while (send[i])
	{
		if (send[i] == '1')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		wait_sig();
	}
	free(send);
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
	{
		ft_putstr_fd("The client need the pid and a string\n", 1);
		exit(EXIT_FAILURE);
	}
	while (argv[1][i] != '\0')
	{
		if (ft_isdigit(argv[1][i++]) == 0)
			exit(EXIT_FAILURE);
	}
	i = 0;
	signal(SIGUSR2, handler);
	while (argv[2][i] != '\0')
		send_ascii(atoi(argv[1]), argv[2][i++]);
	i = 0;
	while (i < 7)
	{
		kill(atoi(argv[1]), SIGUSR1);
		wait_sig();
		i++;
	}
	return (EXIT_SUCCESS);
}
