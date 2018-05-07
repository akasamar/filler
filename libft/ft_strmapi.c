/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:01:13 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/20 18:01:52 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			p[i] = f(i, s[i]);
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (NULL);
}
