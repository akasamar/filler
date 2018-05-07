/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:48:40 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/20 18:48:43 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*p;

	if (s1 && s2)
	{
		size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
		if (!(p = (char *)malloc(size + 1)))
			return (NULL);
		ft_strcpy(p, s1);
		ft_strcat(p, s2);
		return (p);
	}
	return (NULL);
}
