/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:29:27 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 14:54:16 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ss1;
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	if (!s1)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start <= end && ft_strchr(set, s1[start]))
		start++;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	ss1 = ft_calloc(((end - start + 1) + 1), sizeof(char));
	if (!ss1)
		return (NULL);
	while (i < (end - start + 1))
	{
		ss1[i] = s1[start + i];
		i++;
	}
	ss1[i] = '\0';
	return (ss1);
}
