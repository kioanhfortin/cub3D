/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:01:32 by seroy             #+#    #+#             */
/*   Updated: 2023/03/22 15:04:04 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ts1;
	int		i;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ts1 = (char *)malloc((lens1 + lens2 + 1) * sizeof(char));
	i = 0;
	if (!s1 || !s2 || !ts1)
		return (NULL);
	while (s1[i])
	{
		ts1[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		ts1[lens1 + i] = s2[i];
		i++;
	}
	ts1[lens1 + i] = '\0';
	return (ts1);
}
