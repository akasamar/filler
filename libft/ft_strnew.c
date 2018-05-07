/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:09:06 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/15 20:09:10 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *p;

	if (size == 0)
		size = 1;
	if (size > 9223372036854775807 || size < 1)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p)
		ft_bzero(p, size + 1);
	else
		return (NULL);
	return (p);
}
