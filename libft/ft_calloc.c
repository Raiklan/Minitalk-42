/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:47:17 by saich             #+#    #+#             */
/*   Updated: 2019/10/22 17:41:48 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *dest;

	if (count == 0 || size == 0)
	{
		count = 1;
		size = 1;
	}
	if (!(dest = malloc(size * count)))
		return (NULL);
	ft_bzero(dest, count * size);
	return (dest);
}
