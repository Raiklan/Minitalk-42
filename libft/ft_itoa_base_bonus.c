/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:09:00 by saich             #+#    #+#             */
/*   Updated: 2019/10/18 14:33:45 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		power(size_t nb, size_t powa)
{
	if (powa < 0)
		return (0);
	if (powa == 0)
		return (1);
	return (nb * power(nb, powa - 1));
}

static int		nega(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static int		checkbase(char *base)
{
	size_t	b;
	int		i;
	int		j;

	b = ft_strlen(base);
	if (b < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == 32 || (base[i] >= 9 && base[i] <= 13) || base[i] == '+'
		|| base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char			*ft_itoa_base(int nbr, char *base)
{
	char	*dest;
	int		nb;
	int		j;
	size_t	i;

	i = 0;
	j = 0;
	nb = nbr;
	if (checkbase(base) == 1)
	{
		while (nb != 0 && i++ <= 2147483647)
			nb /= ft_strlen(base);
		if (!(dest = malloc(sizeof(char) * i + nbr < 0 ? 1 : 0)))
			return (0);
		nb = (nega(nbr) == 1 ? -nbr : nbr);
		if (nega(nbr) == 1)
			dest[j++] = '-';
		while (i-- > 0)
			dest[j++] = base[nb / power(ft_strlen(base), i) % ft_strlen(base)];
		dest[j] = '\0';
		return (dest);
	}
	return (NULL);
}
