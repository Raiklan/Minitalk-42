/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:03:48 by user42            #+#    #+#             */
/*   Updated: 2021/11/02 15:16:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void        print_pid(void)
{
    char* pid;
    pid = ft_itoa(getpid());
    write(1, "pid =", 6);
    write(1, pid, ft_strlen(pid));
    write(1, "\n", 1);
    free(pid);
}

void		active_bit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!to_print.top_bit)
	{
		to_print.top_bit = 1 << 6;
		++(to_print.top_byte);
	}
	to_print.message[to_print.top_byte] += to_print.top_bit;
	to_print.top_bit >>= 1;
	if (to_print.top_byte == BUFFSIZE - 2 && !to_print.top_bit)
		to_print.buffer_oversize = TRUE;
}

void		nullbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!to_print.top_bit)
	{
		to_print.top_bit = 1 << 6;
		++(to_print.top_byte);
	}
	to_print.top_bit >>= 1;
	if (to_print.top_byte == BUFFSIZE - 2 && !to_print.top_bit)
		to_print.buffer_oversize = TRUE;
	else if (!to_print.message[to_print.top_byte]
		&& !to_print.top_bit)
	{
		to_print.received = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool		main_handler(void)
{
	while (1)
	{
		pause();
		if (to_print.received || to_print.buffer_oversize)
		{
			write(1, to_print.message, ft_strlen(to_print.message));
			ft_bzero(to_print.message, BUFFSIZE);
			to_print.top_byte = 0;
			to_print.top_bit = 1 << 6;
			if (to_print.received)
				write(1, "\n", 1);
			to_print.received = FALSE;
			to_print.buffer_oversize = FALSE;
		}
	}
	return (TRUE);
}


int			main(void)
{
	struct sigaction active_action;
	struct sigaction null_action;

	active_action.sa_sigaction = activebit();
	null_action.sa_sigaction = nullbit();
	active_action.sa_flags = SA_SIGINFO;
	null_action.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_action, NULL) != 0)
		error("signal error\n");
	if (sigaction(SIGUSR2, &null_action, NULL) != 0)
		error("signal error\n");
	print_pid();
	ft_bzero(to_print.message, BUFFSIZE);
	main_handler();
}

