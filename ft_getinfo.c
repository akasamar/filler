/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getinfo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 23:30:34 by akasamar          #+#    #+#             */
/*   Updated: 2018/05/03 23:30:35 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_getmap_and_token2(char **pole, t_filler *new, int *i)
{
	if (new->mapsize == 'l' && ((*i = 99) || 1))
	{
		while ((*i)--)
		{
			new->map = ft_strjoin(new->map, "\n");
			get_next_line(0, &(*pole));
			new->map = ft_strjoin(new->map, *pole + 4);
		}
	}
	get_next_line(0, &(*pole));
	new->yt = ft_atoi(*pole + 5);
	*i = new->yt - 1;
	get_next_line(0, &(*pole));
	new->token = *pole;
	while ((*i)--)
	{
		new->token = ft_strjoin(new->token, "\n");
		get_next_line(0, &(*pole));
		new->token = ft_strjoin(new->token, *pole);
	}
}

void			ft_getmap_and_token(char **pole, t_filler *new)
{
	int		i;

	get_next_line(0, &(*pole));
	get_next_line(0, &(*pole));
	new->map = *pole + 4;
	if (new->mapsize == 's' && ((i = 14) || 1))
	{
		while (i--)
		{
			new->map = ft_strjoin(new->map, "\n");
			get_next_line(0, &(*pole));
			new->map = ft_strjoin(new->map, *pole + 4);
		}
	}
	else if (new->mapsize == 'm' && ((i = 23) || 1))
	{
		while (i--)
		{
			new->map = ft_strjoin(new->map, "\n");
			get_next_line(0, &(*pole));
			new->map = ft_strjoin(new->map, *pole + 4);
		}
	}
	ft_getmap_and_token2(&(*pole), new, &i);
}

int				ft_checkaround(char *s, int i, t_filler *new)
{
	int stop;

	stop = 0;
	if (s[i + 1] == '1' && ((i + 1) < new->e))
		stop++;
	if (s[i + new->g] == '1' && ((i + new->g) < new->e))
		stop++;
	if (s[i - 1] == '1' && ((i - 1) >= 0))
		stop++;
	if (s[i - new->g] == '1' && ((i - new->g) >= 0))
		stop++;
	if (stop == 4)
		return (0);
	return (1);
}

int				ft_checkenemy(char *s, int i, t_filler *new)
{
	if (s[i + 1] == new->en && ((i + 1) < new->e))
		return (1);
	if (s[i + new->g] == new->en && ((i + new->g) < new->e))
		return (1);
	if (s[i - 1] == new->en && ((i - 1) >= 0))
		return (1);
	if (s[i - new->g] == new->en && ((i - new->g) >= 0))
		return (1);
	return (0);
}

int				ft_2in1(char **s, int i, int k, t_filler *new)
{
	char *s2;

	s2 = *s;
	if (k == 1)
	{
		while (s2[++i])
			if (s2[i] == '2')
				s2[i] = '1';
	}
	if (k == 2)
	{
		if ((s2[i + 1] == '.' || s2[i + 1] == new->me) \
			&& ((i + 1) < new->e))
			s2[i + 1] = '2';
		if ((s2[i + new->g] == '.' || s2[i + new->g] == new->me) \
			&& ((i + new->g) < new->e))
			s2[i + new->g] = '2';
		if ((s2[i - 1] == '.' || s2[i - 1] == new->me) && ((i - 1) >= 0))
			s2[i - 1] = '2';
		if ((s2[i - new->g] == '.' || s2[i - new->g] == new->me) \
			&& ((i - new->g) >= 0))
			s2[i - new->g] = '2';
	}
	*s = s2;
	return (1);
}
