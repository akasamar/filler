/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:13:19 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/07 21:33:47 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned long	res;
	int				minus;

	res = 0;
	minus = 1;
	while ((*str >= 9 && *str <= 13) || (*str == ' '))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - 48);
		if (res > 9223372036854775807 && minus == 1)
			return (-1);
		else if (res > 9223372036854775807 && minus == -1)
			return (0);
		str++;
	}
	return (res * minus);
}
