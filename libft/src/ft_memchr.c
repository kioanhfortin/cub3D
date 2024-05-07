/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:57:53 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 14:51:29 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned long int		i;
	unsigned char			*s2;

	s2 = (unsigned char *)s;
	i = 0;
	if (!s || !s2)
		return (NULL);
	while (i < n)
	{
		if (*s2 == (unsigned char)c)
			return (s2);
		i++;
		s2++;
	}
	return (NULL);
}
