/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 20:30:24 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/06 14:56:44 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;
	char	cpy[len];

	if (len > 128 * 1024)
		return (NULL);
	d = (char *)dst;
	s = (char *)src;
	ft_memcpy(cpy, src, len);
	ft_memcpy(dst, cpy, len);
	return (dst);
}
