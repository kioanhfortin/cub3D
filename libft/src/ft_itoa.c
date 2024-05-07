/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 16:47:45 by seroy             #+#    #+#             */
/*   Updated: 2023/02/22 12:14:03 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	ft_checklen(int n)
{
	unsigned int	res;

	if (n < 0)
		res = n * -1;
	else
		res = n;
	if (res >= 1000000000)
		return (10);
	else if (res >= 100000000)
		return (9);
	else if (res >= 10000000)
		return (8);
	else if (res >= 1000000)
		return (7);
	else if (res >= 100000)
		return (6);
	else if (res >= 10000)
		return (5);
	else if (res >= 1000)
		return (4);
	else if (res >= 100)
		return (3);
	else if (res >= 10)
		return (2);
	return (1);
}

char	*ft_itoa(int n)
{
	char			*res;
	unsigned int	nlen;
	long int		nb;

	nb = (long int)n;
	nlen = ft_checklen(nb) + ft_sign(nb);
	res = (char *)malloc(((char)nlen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (nb < 0)
		nb *= -1;
	res[nlen] = '\0';
	nlen--;
	if (nb == 0)
		res[nlen] = '0';
	while (nlen >= 0 && nb > 0)
	{
		res[nlen] = nb % 10 + 48;
		nb /= 10;
		nlen--;
	}
	if (ft_sign(n) == 1)
		res[nlen] = '-';
	return (res);
}
