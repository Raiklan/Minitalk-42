/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:03:48 by user42            #+#    #+#             */
/*   Updated: 2021/10/29 16:46:12 by user42           ###   ########.fr       */
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

int main(int argc, char **argv)
{
    
}
