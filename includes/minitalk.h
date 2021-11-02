/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 15:51:09 by user42            #+#    #+#             */
/*   Updated: 2021/11/02 15:23:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MINITALK_H
# define _MINITALK_H

# define BUFFSIZE 1024

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

# include <zconf.h>
# include <signal.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <bits/types/siginfo_t.h>

typedef struct	s_stack
{
	char		message[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	_Bool		received;
	_Bool		buffer_oversize;
}				t_stack;

t_stack         to_print = {{0}, 1 << 6, 0, FALSE, FALSE};

int			ft_atoi(const char *str);
char		*ft_itoa(int n);
void        error(char* string_error);
void		ft_bzero(void *s, size_t n);


#endif