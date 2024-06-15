/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:53 by seroy             #+#    #+#             */
/*   Updated: 2024/05/20 17:53:27 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	flood_fill(char **map, int x, int y)
{
	if (x < 0 || y < 0)
		return (-1);
	if (map[y] == NULL || map[y][x] == '\n' || map[y][x] == 0)
		return (-1);
	if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == ' ' || map[y][x] == '2')
		return (0);
	map[y][x] = 'X';
	if (flood_fill(map, x + 1, y) == -1)
		return (-1);
	if (flood_fill(map, x - 1, y) == -1)
		return (-1);
	if (flood_fill(map, x, y + 1) == -1)
		return (-1);
	if (flood_fill(map, x, y - 1) == -1)
		return (-1);
	return (0);
}

int	pre_flood(t_data *data)
{
	char	**map2;
	int		x;
	int		y;

	map2 = ft_copy_map(data->map);
	data->height = ft_height(data->map);
	x = ft_strchr_x(map2, data->facing);
	y = ft_strchr_y(map2, data->facing);
	data->map[y][x] = '0';
	data->player.x = x + 0.5;
	data->player.y = y + 0.5;
	if (flood_fill(map2, x, y) == -1)
	{
		free_map(map2);
		errmessage(13, NULL, data);
	}
	free_map(map2);
	return (0);
}

int	empty_line(char *s)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]))
		{
			num = 1;
			return (0);
		}
		i++;
	}
	return (1);
}
