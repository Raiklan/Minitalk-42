/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 12:17:59 by exam              #+#    #+#             */
/*   Updated: 2021/11/03 03:20:46 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	loc_word(char *s, char c, unsigned int i)
{
	int				word;
	unsigned int	count_word;
	unsigned int	loc;

	word = 0;
	count_word = 0;
	loc = 0;
	while (s[loc] != '\0')
	{
		if (word == 0 && s[loc] != c)
		{
			count_word++;
			if (count_word == i + 1)
				break ;
			word = 1;
		}
		else if (word == 1 && s[loc] == c)
			word = 0;
		loc++;
	}
	return (loc);
}

static int	count(char *s, char c)
{
	int				word;
	unsigned int	count_word;

	count_word = 0;
	word = 0;
	while (*s != '\0')
	{
		if (word == 0 && *s != c)
		{
			count_word++;
			word = 1;
		}
		else if (word == 1 && *s == c)
			word = 0;
		s++;
	}
	return (count_word);
}

static char	*put_word(char *s, char c)
{
	unsigned int	i;
	unsigned int	n;
	char			*res;

	n = 0;
	while (s[n] != '\0' && s[n] != c)
		n++;
	res = (char *)malloc(sizeof(char) * (n + 1));
	if (!(res))
	{
		free(res);
		return (NULL);
	}
	i = 0;
	while (i < n)
		res[i++] = *s++;
	res[i] = '\0';
	return (res);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	nb;
	unsigned int	i;
	char			**res;
	char			*str;

	if (!s)
		return (0);
	str = (char *)s;
	nb = count(str, c);
	res = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!(res))
	{
		free(res);
		return (0);
	}
	i = 0;
	while (i < nb)
	{
		res[i] = put_word(str + loc_word(str, c, i), c);
		i++;
	}
	res[i] = 0;
	return (res);
}
