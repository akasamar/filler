/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 16:39:40 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/05 18:57:04 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	k;
	char	*s1;
	char	*s2;

	k = 0;
	s1 = (char *)dst;
	s2 = (char *)src;
	while (k < n)
	{
		s1[k] = s2[k];
		k++;
	}
	return (dst);
}
