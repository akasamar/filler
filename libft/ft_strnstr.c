/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:29:58 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/07 21:02:12 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ukaz2(int *i, int *k, int *l)
{
	*i = 0;
	*k = 0;
	*l = 0;
}

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	int i;
	int k;
	int l;
	int save;

	ukaz2(&i, &k, &l);
	if (*s2 == '\0')
		return ((char *)s1);
	while (s2[l])
		l++;
	while (s1[i])
	{
		save = i;
		while (s1[save] == s2[k] && save < (int)len)
		{
			save++;
			k++;
			if (k == l)
				return ((char *)&s1[save - l]);
		}
		k = 0;
		i++;
	}
	return (NULL);
}
