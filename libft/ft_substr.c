/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:19:52 by saich             #+#    #+#             */
/*   Updated: 2019/10/15 16:36:05 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*ret;
	char	*cpy_ret;

	if (!s || !(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start > ft_strlen(s))
		ret[0] = '\0';
	else
	{
		ptr = (char *)s + start;
		cpy_ret = ret;
		while (*ptr && len-- > 0)
			*cpy_ret++ = *ptr++;
		*cpy_ret = '\0';
	}
	return (ret);
}
