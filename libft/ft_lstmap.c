/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:03:38 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/27 19:03:39 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*movelist;

	if (lst)
	{
		movelist = f(lst);
		new = movelist;
		while (lst->next)
		{
			lst = lst->next;
			if (!(movelist->next = f(lst)))
			{
				free(movelist->next);
				return (NULL);
			}
			movelist = movelist->next;
		}
		return (new);
	}
	return (NULL);
}
