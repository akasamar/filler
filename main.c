/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:29:19 by akasamar          #+#    #+#             */
/*   Updated: 2018/05/02 23:29:30 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static	t_filler	fill_struct(void)
{
	t_filler new;

	new.me = 'X';
	new.en = 'O';
	new.yt = 0;
	new.x = 0;
	new.y = 0;
	new.mapsize = 'l';
	new.map = NULL;
	new.token = NULL;
	new.bestpoint = 99999;
	new.bestcoord = -1;
	new.bestplace = 0;
	new.g = 0;
	new.e = 0;
	new.mysteps = 0;
	return (new);
}

static	void		get_size_map(char **pole, t_filler *new)
{
	if (ft_atoi(*pole + 8) == 15 && ft_atoi(*pole + 11) == 17)
		new->mapsize = 's';
	else if (ft_atoi(*pole + 8) == 24 && ft_atoi(*pole + 11) == 40)
		new->mapsize = 'm';
	if (new->mapsize == 's')
	{
		new->g = 18;
		new->e = 270;
	}
	else if (new->mapsize == 'm')
	{
		new->g = 41;
		new->e = 984;
	}
	else if (new->mapsize == 'l')
	{
		new->g = 100;
		new->e = 10000;
	}
}

static	int			ft_move(char **pole, t_filler *new)
{
	char	*s;

	get_next_line(0, &(*pole));
	s = *pole;
	if ((ft_strstr(*pole, " p1 ") || ft_strstr(*pole, " p2 ")) \
		&& get_next_line(0, &(*pole)))
	{
		get_size_map(&(*pole), new);
		if ((ft_strstr(s, " p1 ")))
		{
			new->me = 'O';
			new->en = 'X';
		}
		return (1);
	}
	else if (ft_strstr(*pole, "Plateau") != NULL)
		return (1);
	else
		return (0);
}

int					main(void)
{
	char		*pole;
	t_filler	new;

	new = fill_struct();
	while (1)
	{
		if (ft_move(&pole, &new) == 1)
		{
			ft_getmap_and_token(&pole, &new);
			ft_findpoint(new.map, &new);
			ft_putnbr(new.y);
			ft_putchar(' ');
			ft_putnbr(new.x);
			ft_putchar('\n');
			new.bestpoint = 99999;
			new.bestcoord = -1;
			new.y = 0;
			new.x = 0;
			new.mysteps++;
		}
		else
			break ;
	}
	return (0);
}
