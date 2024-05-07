/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:31:59 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 14:53:22 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	ssrc;
	size_t	sdst;

	sdst = ft_strlen(dst);
	ssrc = ft_strlen(src);
	i = 0;
	if (!dst || !src)
		return (0);
	if (dstsize < 0)
		return (0);
	if (sdst > dstsize)
		sdst = dstsize;
	if (dstsize <= sdst)
		return (sdst + ssrc);
	j = 0;
	while (src[j] && j < dstsize - sdst - 1)
	{
		dst[sdst + j] = src[j];
		j++;
	}
	if (dstsize != 0)
		dst[sdst + j] = '\0';
	return (sdst + ssrc);
}
