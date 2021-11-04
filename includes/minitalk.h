/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/19 19:58:48 by rtulchiy          #+#    #+#             */
/*   Updated: 2021/11/04 16:59:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define BUFFSIZE 1024

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif

typedef struct s_stack
{
	char		message[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	_Bool		all_receive;
	_Bool		buff_overflow;
}				t_stack;

t_stack			g_to_print = {{0}, 1 << 6, 0, FALSE, FALSE};

void			error(char *str_error);

#endif
