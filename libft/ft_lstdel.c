/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 17:56:57 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/27 17:57:11 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*dva;
	t_list	*adin;

	dva = *alst;
	while (dva)
	{
		adin = dva->next;
		del(dva->content, dva->content_size);
		free(dva);
		dva = adin;
	}
	*alst = NULL;
}
