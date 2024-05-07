/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:39 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:29:08 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

uint32_t	**ft_resize_tex(t_data *data, mlx_texture_t *tex_Wall,
		uint32_t **dest_data)
{
	data->x_ratio = (float)tex_Wall->width / 100;
	data->y_ratio = (float)tex_Wall->height / 100;
	dest_data = malloc(sizeof(uint32_t *) * (TEX_HEIGHT));
	if (!dest_data)
		ft_safety(dest_data, data);
	data->w = 0;
	while (data->w < 100)
	{
		dest_data[data->w] = malloc(sizeof(uint32_t) * (TEX_WIDTH));
		if (!dest_data[data->w])
			ft_safety_small(dest_data, data->w, data);
		data->src_y = (int)(data->w * data->y_ratio);
		data->q = 0;
		while (data->q < 100)
		{
			data->src_x = (int)(data->q * data->x_ratio);
			data->e = (data->src_y * tex_Wall->width * 4) + (data->src_x * 4);
			dest_data[data->w][data->q] = get_rgba(tex_Wall->pixels[data->e],
					tex_Wall->pixels[data->e + 1], tex_Wall->pixels[data->e
					+ 2], tex_Wall->pixels[data->e + 3]);
			data->q++;
		}
		data->w++;
	}
	return (dest_data);
}
