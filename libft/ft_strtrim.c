/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 19:29:29 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/20 19:29:30 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_getlens(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char		*create(int k, int l, char const *s, int k2)
{
	int		n;
	int		i;
	char	*p;

	n = 0;
	i = k;
	if (!(p = (char *)malloc(sizeof(char) + (l + 1))))
		return (NULL);
	i = k;
	while (i <= k2)
		p[n++] = s[i++];
	p[n] = '\0';
	return (p);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		k;
	int		k2;
	char	*p;
	int		l;

	p = NULL;
	if (!s)
		return (NULL);
	else if (!s[0])
		return ((char *)s);
	i = 0;
	while (s[i] == '\t' || s[i] == ' ' || s[i] == '\n')
		i++;
	k = i;
	i = ft_getlens(s) - 1;
	while ((s[i] == '\t' || s[i] == ' ' || s[i] == '\n') && s[i])
		i--;
	k2 = i;
	l = k2 - k;
	if (k2 < k)
		l = 1;
	return (create(k, l, s, k2));
}
