/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 18:49:14 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/07 19:16:03 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ukaz(int *i, int *k, int *len)
{
	*i = 0;
	*k = 0;
	*len = 0;
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int k;
	int len;
	int save;

	ukaz(&i, &k, &len);
	if (*needle == '\0')
		return ((char *)haystack);
	while (needle[len])
		len++;
	while (haystack[i])
	{
		save = i;
		while (haystack[save] == needle[k])
		{
			save++;
			k++;
			if (k == len)
				return ((char *)&haystack[save - len]);
		}
		k = 0;
		i++;
	}
	return (NULL);
}
