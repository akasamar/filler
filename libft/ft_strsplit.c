/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/25 19:40:23 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/25 19:40:28 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *new, char c)
{
	int i;
	int words;

	i = -1;
	words = 0;
	if (new[0] == '\0')
		return (0);
	while (new[++i] == c)
		if (new[i] == c && new[i + 1] == '\0')
			return (0);
	i = 0;
	while (new[i] == c)
		i++;
	while (new[i])
	{
		if (new[i] == c && new[i + 1] != c && new[i + 1] != '\0')
			words++;
		i++;
	}
	return (words + 1);
}

static char		*ft_everword(char const *s, char c, int *i)
{
	char	*p;
	int		index;
	int		save;

	save = *i;
	index = 0;
	while (s[*i] != c && s[*i])
		*i += 1;
	if (!(p = (char *)malloc(sizeof(char) * (*i - save + 1))))
		return (NULL);
	while (save <= *i && s[save] != c && s[save])
		p[index++] = s[save++];
	p[index] = '\0';
	return (p);
}

static char		**check(int word, char **p)
{
	if (word == 0)
	{
		if (!(p = (char **)malloc(sizeof(char *) * 1)))
			return (0);
		p[0] = NULL;
		return (p);
	}
	return (p);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**p;
	int		words;
	int		i;
	int		k;

	i = 0;
	k = 0;
	p = NULL;
	if (!s)
		return (0);
	words = ft_words(s, c);
	if (words == 0)
		return (check(words, p));
	if (!(p = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	while (words--)
	{
		while (s[i] == c && s[i])
			i++;
		p[k++] = ft_everword(s, c, &i);
	}
	p[k] = NULL;
	return (p);
}
