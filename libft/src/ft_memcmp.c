/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:25:51 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 16:37:27 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*s3;
	char	*s4;

	s3 = (char *)s1;
	s4 = (char *)s2;
	i = 0;
	if (!s3 || !s4 || n == 0)
		return (0);
	while (i < n - 1)
	{
		if (s3[i] != s4[i])
		{
			return ((unsigned char)s3[i] - (unsigned char)s4[i]);
		}
		i++;
	}
	return ((unsigned char)s3[i] - (unsigned char)s4[i]);
}
