/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:21:34 by saich             #+#    #+#             */
/*   Updated: 2021/11/03 03:06:28 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int frees1, int frees2)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = malloc(sizeof(char) * len);
	if (!(str))
	{
		free(str);
		return (NULL);
	}
	str = ft_strcpy(str, s1);
	str = ft_strcat(str, s2);
	if (s1 == s2 && (frees1 || frees2))
	{
		free((char *)s1);
		return (str);
	}
	if (frees1)
		free((char *)s1);
	if (frees2)
		free((char *)s2);
	return (str);
}
