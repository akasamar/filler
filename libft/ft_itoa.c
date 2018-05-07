/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:42:26 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/27 20:08:13 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		countof(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		n = -n;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char		*reverse(char *p)
{
	int		k1;
	int		k2;
	char	s;

	k1 = 0;
	k2 = 0;
	while (p[k2])
		k2++;
	k2 -= 1;
	while (k1 < k2)
	{
		s = p[k2];
		p[k2--] = p[k1];
		p[k1++] = s;
	}
	return (p);
}

static char		*minus(int n, int k)
{
	char	*p;
	int		i;

	if (!(p = (char *)malloc(sizeof(char) * (k + 2))))
		return (NULL);
	i = 0;
	n *= -1;
	while (n > 9)
	{
		p[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	p[i++] = (n % 10) + 48;
	p[i++] = '-';
	p[i] = '\0';
	return (reverse(p));
}

static char		*plus(int n, int k)
{
	char	*p;
	int		i;

	if (!(p = (char *)malloc(sizeof(char) * (k + 1))))
		return (NULL);
	i = 0;
	while (n > 9)
	{
		p[i] = (n % 10) + 48;
		n /= 10;
		i++;
	}
	p[i++] = (n % 10) + 48;
	p[i] = '\0';
	return (reverse(p));
}

char			*ft_itoa(int n)
{
	int k;

	k = countof(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n >= 0)
		return (plus(n, k));
	if (n < 0)
		return (minus(n, k));
	return (NULL);
}
