/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:15:48 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 14:52:38 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_str(char const *str, char c)
{
	int		num;
	size_t	i;

	num = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			num++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (num);
}

static void	*ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**tab;
	unsigned int	last_pos;
	unsigned int	i;
	int				k;

	tab = ft_calloc((ft_num_str(s, c) + 1), sizeof(char *));
	if (!tab || !s)
		return (NULL);
	i = 0;
	k = 0;
	while (k < ft_num_str(s, c))
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			last_pos = i;
		while (s[i] && s[i] != c)
			i++;
		tab[k] = ft_substr(s, last_pos, (i - last_pos));
		if (!tab[k])
			return (ft_free(tab));
		k++;
	}
	return (tab);
}
