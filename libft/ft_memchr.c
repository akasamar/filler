/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:08:21 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/06 15:31:30 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			k;
	unsigned char	*zal;

	k = 0;
	zal = (unsigned char*)s;
	while (k < n)
	{
		if (zal[k] == (unsigned char)c)
			return (&zal[k]);
		k++;
	}
	return (0);
}
