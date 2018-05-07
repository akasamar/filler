/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:15:12 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/20 18:15:14 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;

	i = 0;
	if (s)
	{
		if (len == 0)
			return (ft_strnew(1));
		if (!s || (p = ft_strnew(len)) == 0)
			return (NULL);
		while (len--)
			p[i++] = s[start++];
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
