/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:27 by seroy             #+#    #+#             */
/*   Updated: 2024/05/02 11:23:36 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	facing_ew(t_data *data)
{
	if (data->facing == WEST)
	{
		data->dirx = 1;
		data->diry = 0;
		data->planex = 0;
		data->planey = -0.66;
	}
	if (data->facing == EAST)
	{
		data->dirx = -1;
		data->diry = 0;
		data->planex = 0;
		data->planey = 0.66;
	}
}

void	set_player_angle(t_data *data)
{
	if (data->facing == NORTH)
	{
		data->dirx = 0;
		data->diry = -1;
		data->planex = -0.66;
		data->planey = 0;
	}
	if (data->facing == SOUTH)
	{
		data->dirx = 0;
		data->diry = 1;
		data->planex = 0.66;
		data->planey = 0;
	}
	facing_ew(data);
}

int	ver_char(t_data *data, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (data->facing != -1)
			errmessage(12, NULL, data);
		else
		{
			if (c == 'N')
				data->facing = NORTH;
			if (c == 'S')
				data->facing = SOUTH;
			if (c == 'E')
				data->facing = EAST;
			if (c == 'W')
				data->facing = WEST;
			return (1);
		}
	}
	if (c == '0' || c == '1' || c == ' ' || c == '\n')
		return (1);
	return (0);
}

int	parse_map(t_data *data, char **map)
{
	int	i;
	int	j;
	int	eom;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		eom = empty_line(map[i]);
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (!ver_char(data, map[i][j]))
				errmessage(7, ft_substr(map[i], j, 1), data);
			j++;
		}
		i++;
		if (map[i] && !empty_line(map[i]) && eom)
			errmessage(16, NULL, data);
	}
	if (data->facing == -1)
		errmessage(14, NULL, data);
	set_player_angle(data);
	return (1);
}

char	**ft_copy_map(char **map)
{
	int		i;
	int		ilen;
	char	**map2;

	i = 0;
	ilen = ft_height(map);
	map2 = ft_calloc((ilen + 1), sizeof(*map2));
	if (!map2)
	{
		free(map2);
		map2 = NULL;
		return (0);
	}
	while (map[i])
	{
		map2[i] = ft_strdup(map[i]);
		i++;
	}
	return (map2);
}
