/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:52 by seroy             #+#    #+#             */
/*   Updated: 2024/05/01 11:57:55 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ver_path(t_data *data)
{
	if (open(data->path[NORTH], O_RDONLY) == -1)
		return (errmessage(6, data->path[NORTH], data), 1);
	if (open(data->path[SOUTH], O_RDONLY) == -1)
		return (errmessage(6, data->path[SOUTH], data), 1);
	if (open(data->path[EAST], O_RDONLY) == -1)
		return (errmessage(6, data->path[EAST], data), 1);
	if (open(data->path[WEST], O_RDONLY) == -1)
		return (errmessage(6, data->path[WEST], data), 1);
	return (0);
}

int	ft_colnum(char *s)
{
	if (ft_strlen(s) > 10 || (ft_strlen(s) == 10
			&& ft_strcmp(s, "2147483647") > 0))
		return (1);
	if (ft_atoi(s) < 0 || ft_atoi(s) > 255)
		return (1);
	return (0);
}

int	ver_color(char *str, t_data *data)
{
	data->m = 0;
	data->len = 0;
	data->count = 0;
	while (str[data->m])
	{
		if (ft_isdigit(str[data->m]))
		{
			data->count++;
			while (ft_isdigit(str[data->m]))
			{
				data->m++;
				data->len++;
			}
			data->tmp = ft_substr(str, data->m - data->len, data->len);
			if (ft_colnum(data->tmp))
				errmessage(11, data->tmp, data);
			free(data->tmp);
			data->len = 0;
		}
		if (str[data->m] != 0)
			data->m++;
	}
	if (data->count != 3)
		errmessage(11, NULL, data);
	return (1);
}

int	ver_map(t_data *data)
{
	if (!parse_map(data, data->map))
		return (1);
	if (!pre_flood(data))
		return (1);
	return (0);
}

int	ver_data(t_data *data)
{
	if (ver_path(data))
		return (1);
	if (!ver_color(data->path[FLOOR], data) || !ver_color(data->path[CEILING],
			data))
		return (1);
	if (ver_map(data))
		return (1);
	return (0);
}
