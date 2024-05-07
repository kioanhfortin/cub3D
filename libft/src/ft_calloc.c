/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:08 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 14:54:59 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;
	size_t	i;

	a = malloc(count * size);
	i = 0;
	if (a == NULL)
		return (NULL);
	while (i < count * size)
	{
		((char *)a)[i] = 0;
		i++;
	}
	return (a);
}
