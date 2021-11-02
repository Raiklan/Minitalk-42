/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:24:10 by saich             #+#    #+#             */
/*   Updated: 2019/10/16 17:07:38 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst)
		return ;
	if (!*alst)
		*alst = new;
	else if (*alst && new)
	{
		tmp = *alst;
		new->next = tmp;
		*alst = new;
	}
}
