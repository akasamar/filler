/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_themostbignum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 22:57:01 by akasamar          #+#    #+#             */
/*   Updated: 2017/12/03 22:57:03 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_themostmaxnum(int *num, int len)
{
	int i;
	int j;

	i = 0;
	j = num[i];
	while (i < len - 1)
	{
		if (num[i] > j)
			j = num[i];
		i++;
	}
	return (j);
}
