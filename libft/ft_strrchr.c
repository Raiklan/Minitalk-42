/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:29:12 by saich             #+#    #+#             */
/*   Updated: 2019/10/21 16:25:34 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;
	char	*cur;

	start = (char*)s;
	cur = start;
	while (*cur != '\0')
		cur++;
	while (cur >= start)
	{
		if (*cur == (char)c)
			return (cur);
		cur--;
	}
	return (0);
}
