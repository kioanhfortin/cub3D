/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:20:01 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 16:55:49 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst2;
	char		*src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	if (!dst2 || !src2 || !src || !dst)
		return (dst);
	if (dst2 > src2)
	{
		while (len > 0)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
		return ((void *)dst2);
	}
	while (i < len)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}
