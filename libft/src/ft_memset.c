/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:13:28 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 17:03:38 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*b2;

	b2 = (char *)b;
	i = 0;
	if (!b)
		return (NULL);
	while (i < (int)len)
	{
		b2[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
