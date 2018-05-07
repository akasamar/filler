/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbestpoint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:30:13 by akasamar          #+#    #+#             */
/*   Updated: 2018/05/02 23:30:26 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		ft_findway(char *s, int i, t_filler *new)
{
	int check;
	int step;

	s[i] = '1';
	i = -1;
	step = 0;
	check = 0;
	while (1)
	{
		i = -1;
		while (s[++i])
		{
			if (s[i] == '1' && ft_checkaround(s, i, new))
			{
				if (ft_checkenemy(s, i, new) && ((check = 0) || 1))
					break ;
				ft_2in1(&s, i, 2, new);
				check = 1;
			}
		}
		step++;
		if (!(ft_2in1(&s, -1, 1, new) && check == 1 && (check = 0 || 1)))
			break ;
	}
	return (step);
}

static int		ft_checkslashzero(char *token, char *s, int i, t_filler *new)
{
	int k;
	int save;

	k = 0;
	save = i;
	while (token[k])
	{
		if (s[i] == '\0')
			return (1);
		if (token[k] == '\n')
		{
			k++;
			i = save + new->g;
			save = i;
			continue ;
		}
		k++;
		i++;
	}
	return (0);
}

static int		ft_tokenonmap(char *token, char *s, int i, t_filler *new)
{
	int k;
	int check;
	int v;

	k = 0;
	check = 0;
	v = i;
	while (token[k])
	{
		token[k] == '*' && s[i] == new->me && ++check ? new->bestcoord = v : 1;
		if ((token[k] == '*' && s[i] == new->en)
			|| (token[k] != '\n' && s[i] == '\n'))
			return (0);
		if (token[k] == '\n')
		{
			k++;
			i = v + new->g;
			v = i;
			continue ;
		}
		k++;
		i++;
	}
	return (check != 1 ? 0 : 1);
}

static int		check_x(char *s, t_filler *new)
{
	int i;
	int plus;

	i = -1;
	plus = 0;
	while (s[++i])
	{
		if (s[i] == new->en)
			plus++;
		if (plus > 1)
			return (0);
	}
	if (plus == 1)
	{
		new->y = 0;
		new->x = 0;
		return (1);
	}
	return (0);
}

void			ft_findpoint(char *s, t_filler *new)
{
	int		i;
	int		bestway;
	char	*s2;

	i = -1;
	while (s[++i])
	{
		if (ft_checkslashzero(new->token, s, i, new))
			break ;
		if (new->mysteps > 5 && check_x(s, new))
			break ;
		if (ft_tokenonmap(new->token, s, i, new))
		{
			s2 = ft_strdup(s);
			bestway = ft_findway(s2, i, new);
			free(s2);
			if (bestway < new->bestpoint)
			{
				new->bestpoint = bestway;
				new->bestcoord = i;
				new->y = new->bestcoord / new->g;
				new->x = new->bestcoord % new->g;
			}
		}
	}
}
