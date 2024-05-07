/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:15:03 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 14:52:57 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ms1;
	int		i;

	ms1 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char));
	i = 0;
	if (!ms1 || !s1)
		return (NULL);
	while (s1[i])
	{
		((char *)ms1)[i] = ((char *)s1)[i];
		i++;
	}
	ms1[i] = '\0';
	if (ft_strlen(ms1) < ft_strlen(s1))
	{
		return (NULL);
	}
	return (ms1);
}
