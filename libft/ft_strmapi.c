/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:24:56 by saich             #+#    #+#             */
/*   Updated: 2021/11/03 03:08:23 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*ret;

	if (s == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		;
	ret = (char *)malloc(sizeof(*ret) * (i + 1));
	if (!(ret))
	{
		free(ret);
		return (NULL);
	}
	i = -1;
	while (s[++i])
		ret[i] = f(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
