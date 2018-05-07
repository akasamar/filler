/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 17:36:22 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/20 17:37:32 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	size;
	char	*p;
	int		i;

	i = 0;
	if (s)
	{
		size = ft_strlen((char *)s);
		if (!(p = (char *)malloc(size + 1)))
			return (NULL);
		while (s[i])
		{
			p[i] = f(s[i]);
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
