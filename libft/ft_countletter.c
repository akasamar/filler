/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countletter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:47:01 by akasamar          #+#    #+#             */
/*   Updated: 2017/12/03 22:47:07 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countletter(char *s, char c)
{
	int i;

	i = 0;
	if (s)
		while (*s)
		{
			if (*s == c)
				++i;
			s++;
		}
	return (i);
}
