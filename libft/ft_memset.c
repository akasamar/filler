/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:45:27 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/05 18:40:06 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned char		*zal;

	zal = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		if (i < len)
			zal[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
