/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:45:38 by saich             #+#    #+#             */
/*   Updated: 2019/10/22 17:38:14 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *d, int c, size_t len)
{
	unsigned char	*buf;
	unsigned char	ch;

	buf = (unsigned char *)d;
	ch = (unsigned char)c;
	while (len-- > 0)
		*buf++ = ch;
	return (d);
}
