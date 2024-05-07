/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:48 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:29:16 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	enum_to_direction(char c)
{
	if (c == 0)
		return ('N');
	if (c == 1)
		return ('S');
	if (c == 2)
		return ('E');
	if (c == 3)
		return ('W');
	return (-1);
}

int	ft_strchr_x(char **s, int c)
{
	int	i;
	int	j;

	c = enum_to_direction(c);
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (c == s[i][j])
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strchr_y(char **s, int c)
{
	int	i;
	int	j;

	c = enum_to_direction(c);
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (c == s[i][j])
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_empty_file(char **file)
{
	int	i;
	int	j;

	i = 0;
	if (!file)
		return (1);
	while (file[i])
	{
		j = 0;
		while (file[i][j])
		{
			if (file[i][j] != 32 && ((file[i][j] < 9 || file[i][j] > 13)))
				return (0);
			j++;
		}
		i++;
	}
	if (file[i] == NULL)
		return (1);
	return (0);
}

int	ft_find_width(int i, int j, t_data *data)
{
	int	max;

	max = 0;
	while (data->file[i])
	{
		j = 0;
		while (data->file[i][j])
		{
			j++;
		}
		if (max < j)
			max = j;
		i++;
	}
	return (max);
}
