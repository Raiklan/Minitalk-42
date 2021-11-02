/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saich <saich@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:01:14 by saich             #+#    #+#             */
/*   Updated: 2019/10/17 18:21:03 by saich            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void *content)
{
	t_list *new;

	new = malloc(sizeof(t_list *));
	if (new)
	{
		new->content = content;
		new->next = NULL;
	}
	return (new);
}
