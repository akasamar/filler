/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 23:29:45 by akasamar          #+#    #+#             */
/*   Updated: 2018/05/03 23:34:33 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include <stdio.h>

typedef	struct	s_filler
{
	char		me;
	char		en;
	int			x;
	int			y;
	int			yt;
	char		mapsize;
	char		*map;
	char		*token;
	char		fig;
	int			bestpoint;
	int			bestcoord;
	int			bestplace;
	int			g;
	int			e;
	int			mysteps;
}				t_filler;

void			ft_getmap_and_token(char **pole, t_filler *new);
void			ft_findpoint(char *s2, t_filler *new);
int				ft_checktoken(char *s, int i, char *token, t_filler *new);
int				ft_checkenemy(char *s, int i, t_filler *new);
int				ft_checkaround(char *s, int i, t_filler *new);
int				ft_2in1(char **s, int i, int k, t_filler *new);

#endif
