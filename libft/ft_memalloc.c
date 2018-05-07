/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 17:14:08 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/15 17:19:48 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	p = NULL;
	if (!(p = malloc(sizeof(size))) || size > 9223372036854775807)
		return (NULL);
	ft_memset(p, 0, size);
	return (p);
}
