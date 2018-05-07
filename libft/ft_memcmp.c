/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 15:35:48 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/06 15:48:11 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*zal;
	unsigned char	*zal2;

	i = 0;
	zal = (unsigned char *)s1;
	zal2 = (unsigned char *)s2;
	while (i < n)
	{
		if (zal[i] != zal2[i])
			return (zal[i] - zal2[i]);
		i++;
	}
	return (0);
}
