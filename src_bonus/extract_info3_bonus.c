/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_info3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:36 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:27:34 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_reinit_var(t_data *data)
{
	data->i = 0;
	data->j = 0;
	data->c = 0;
	data->temp = ft_calloc(sizeof(int), 2);
	if (!data->temp)
	{
		ft_free(data);
		exit(1);
	}
}

char	*trim_spaces(t_data *data, char *s, char k)
{
	ft_reinit_var(data);
	while (s[data->i])
	{
		if (ft_isdigit(s[data->i]))
			data->temp[data->j++] = s[data->i];
		else if (s[data->i] == ',' || s[data->i] == '\n')
		{
			if (k == 'C')
				data->ceiling[data->c] = ft_atoi(data->temp);
			else
				data->floor[data->c] = ft_atoi(data->temp);
			free(data->temp);
			data->c++;
			data->j = 0;
			data->temp = ft_calloc(sizeof(int), 2);
			if (!data->temp)
				return (free(data->temp), ft_free(data), exit(1), NULL);
		}
		data->i++;
	}
	if (k == 'C')
		data->ceiling[data->c] = ft_atoi(data->temp);
	else
		data->floor[data->c] = ft_atoi(data->temp);
	return (free(data->temp), data->temp);
}

int	extract_color(char *file, int j, t_data *data)
{
	int		i;
	int		l;
	char	*temp;
	char	*path;

	l = j - 1;
	i = 0;
	find_col_len(data, file, &i, &j);
	if (!ft_isalpha(file[l]))
		errmessage(7, ft_substr(file, j - 2, 1), data);
	temp = ft_substr(file, j - i, i);
	if (ft_strchr(temp, '-'))
		errmessage(11, temp, data);
	path = ft_strtrim(temp, " 	");
	trim_spaces(data, path, file[l]);
	free(temp);
	if (file[l] == 'F')
		data->path[4] = insert_path(data, data->path[FLOOR], path, "FLOOR");
	else if (file[l] == 'C')
		data->path[5] = insert_path(data, data->path[CEILING], path, "CEILING");
	return (j);
}
