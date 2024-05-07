/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 15:03:51 by seroy             #+#    #+#             */
/*   Updated: 2024/03/04 19:27:07 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	unsigned int	nlen;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	nlen = ft_strlen(s);
	if (ft_strlen(s) < start + len)
		len = (nlen - start);
	s2 = (char *)malloc((len + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	ft_strlcpy(s2, s + start, len + 1);
	return (s2);
}
