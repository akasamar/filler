/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:39:41 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/21 18:39:43 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t k;
	size_t p;

	i = 0;
	k = 0;
	while (dst[i])
		i++;
	p = i;
	if (dstsize == 0)
		return (i);
	while (src[k] && i < dstsize - 1)
	{
		dst[i] = src[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	while (src[k])
		k++;
	if (p > dstsize)
		return (k + dstsize);
	return (k + p);
}
