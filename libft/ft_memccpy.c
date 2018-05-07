/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:05:28 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/13 20:05:51 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			k;
	unsigned char	*s1;
	unsigned char	*s2;

	k = 0;
	s1 = (unsigned char *)dst;
	s2 = (unsigned char *)src;
	while (k < n)
	{
		*s1 = s2[k];
		s1++;
		if (s2[k] == (unsigned char)c)
			return (s1);
		k++;
	}
	return (NULL);
}
