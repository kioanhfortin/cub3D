/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:41 by seroy             #+#    #+#             */
/*   Updated: 2024/04/22 15:23:42 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_filecp(t_data *data)
{
	int	i;

	i = 0;
	if (data->file)
	{
		while (data->file[i])
		{
			if (data->file[i])
				free(data->file[i]);
			i++;
		}
		if (data->file)
			free(data->file);
	}
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			if (map[i])
				free(map[i]);
			i++;
		}
		if (map)
			free(map);
	}
}

void	free_tex_buf(uint32_t **buf)
{
	int	i;

	i = 0;
	while (i < TEX_HEIGHT)
	{
		if (buf[i])
			free(buf[i]);
		i++;
	}
	if (buf)
		free(buf);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	free_filecp(data);
	free_map(data->map);
	while (i < 6)
	{
		if (data->path[i])
			free(data->path[i]);
		i++;
	}
	if (!data->n_buf)
		return ;
	ft_free_texture(data);
	if (data->ray->line)
		free(data->ray->line);
	if (data->ray)
		free(data->ray);
}

void	ft_free_texture(t_data *data)
{
	free_tex_buf(data->n_buf);
	free_tex_buf(data->s_buf);
	free_tex_buf(data->e_buf);
	free_tex_buf(data->o_buf);
	if (data->tex_wall_n)
		mlx_delete_texture(data->tex_wall_n);
	if (data->tex_wall_s)
		mlx_delete_texture(data->tex_wall_s);
	if (data->tex_wall_e)
		mlx_delete_texture(data->tex_wall_e);
	if (data->tex_wall_o)
		mlx_delete_texture(data->tex_wall_o);
}
