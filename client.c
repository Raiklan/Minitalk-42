/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:03:42 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 16:46:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdint.h>

void        usage(void)
{
    write(1,"usage : ./client [server_pid] [message]", 40);
    _exit(0);
}

void*       send_char(unsigned char byte, int server_pid)
{
    u_int8_t    mask;

    mask = 1 << 6;
    while (mask)
    {
        if (mask & byte)
        {
            if (kill(server_pid, SIGUSR1) == -1)
                error("Invalid server pid");
        }
        else
        {           
            if (kill(server_pid, SIGUSR2) == -1)
                error("Invalid server pid");
        }
        mask >>= 1;
        usleep(60);
    }
}

void        handler(char *server_pid, char *message)
{
    int serv_pid;

    serv_pid = ft_atoi(server_pid);
    while (*message)
    {
        send_char(serv_pid, *message);
        ++message;
    }
    send_char(serv_pid, *message);
}

void       great_success()
{
    write(1, "Message was sent, my human being\n", 26);    
}


int         main(int argc, char** argv)
{
    if (argc != 3)
        usage();
    sigaction(SIGUSR1, great_success);
    handler(argv[1], argv[2]);
    return(0);
}