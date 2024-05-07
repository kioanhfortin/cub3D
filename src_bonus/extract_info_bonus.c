/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_info_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:30 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:27:27 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*insert_path(t_data *data, char *direction, char *path, char *path_name)
{
	if (direction != NULL)
		errmessage(2, path_name, data);
	else
		direction = ft_strdup(path);
	if (!ft_strncmp(path, "", 1))
		errmessage(4, NULL, data);
	if (path != NULL)
		free(path);
	return (direction);
}

void	find_col_len(t_data *data, char *file, int *i, int *j)
{
	while (file[*j])
	{
		if (ft_isdigit(file[*j]))
		{
			while (file[*j] && ((ft_isdigit(file[*j]) || file[*j] == ',')
					|| file[*j] == ' ' || file[*j] == '	'))
			{
				(*i)++;
				(*j)++;
			}
			break ;
		}
		if (file[*j] != ' ' && file[*j] != '	')
			errmessage(11, NULL, data);
		if (ft_isdigit(file[*j]))
			errmessage(7, ft_substr(file, *j, 1), data);
		(*j)++;
	}
}

void	find_path_len(char *file, int *i, int *j)
{
	while (file[*j])
	{
		if (file[*j] == '.')
		{
			while (file[*j] && !ft_iswhitesp(file[*j]) && file[*j] != '\n')
			{
				(*i)++;
				(*j)++;
			}
			break ;
		}
		(*j)++;
	}
}

int	extract_path(char *file, int j, t_data *data)
{
	int		i;
	int		l;
	char	*path;

	i = 0;
	l = j - 2;
	if (file[j - 2] == 'F' || file[j - 2] == 'C')
		j = extract_color(file, j - 1, data);
	else
	{
		find_path_len(file, &i, &j);
		path = ft_substr(file, j - i, i);
		if (file[l] == 'N')
			data->path[0] = insert_path(data, data->path[NORTH], path, "NORTH");
		else if (file[l] == 'S')
			data->path[1] = insert_path(data, data->path[SOUTH], path, "SOUTH");
		else if (file[l] == 'W')
			data->path[3] = insert_path(data, data->path[WEST], path, "WEST");
		else if (file[l] == 'E')
			data->path[2] = insert_path(data, data->path[EAST], path,
					"EAST");
	}
	return (j);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
