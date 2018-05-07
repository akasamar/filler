/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 19:47:43 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/26 19:48:32 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *p;

	if (!(p = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	if (content == NULL)
	{
		p->content = NULL;
		p->content_size = 0;
	}
	else
	{
		if (!(p->content = malloc(sizeof(content) * content_size)))
			return (0);
		ft_memcpy(p->content, content, content_size);
		p->content_size = content_size;
	}
	p->next = NULL;
	return (p);
}
