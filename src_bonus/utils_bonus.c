/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:45 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:10:28 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	printmess(int fd, char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			printf("%s", map[i]);
			i++;
		}
	}
}

int	ft_iswhitesp(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	ft_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
