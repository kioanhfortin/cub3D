/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_img_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:48:55 by kfortin           #+#    #+#             */
/*   Updated: 2024/05/20 14:20:25 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_player(t_data *data, int32_t i, int32_t y, int32_t color)
{
	int	l;
	int	k;

	k = y;
	l = i;
	while (y - 3 < k + 3)
	{
		i = l;
		while (i - 3 < l + 3)
		{
			if (ft_check_frame(i - 3 + 10, y - 3 + 10) == 0)
				mlx_put_pixel(data->img[2], i - 3 + 10, y - 3 + 10, color);
			i++;
		}
		y++;
	}
}

void	draw_square(t_data *data, int32_t i, int32_t y, int32_t color)
{
	int	l;
	int	k;

	k = y;
	l = i;
	while (y < k + 9)
	{
		i = l;
		while (i < l + 9)
		{
			if (ft_check_frame(i + 10, y + 10) == 0)
				mlx_put_pixel(data->img[1], i + 10, y + 10, color);
			i++;
		}
		y++;
	}
}

void	ft_put_pixel(void *param)
{
	t_data		*data;
	uint32_t	y;
	uint32_t	i;
	uint32_t	color;

	data = param;
	y = 0;
	while (y < (uint32_t)data->height)
	{
		i = 0;
		while (i < (uint32_t)data->width)
		{
			if (data->map[y][i] == '0')
				color = get_rgba(88, 24, 69, 255);
			else if (data->map[y][i] == '1' || data->map[y][i] == '2')
				color = get_rgba(218, 247, 166, 255);
			else
				color = get_rgba(144, 12, 63, 255);
			draw_square(data, i * 10, y * 10, color);
			i++;
		}
		y++;
	}
	color = ft_pixel(0xDC, 0x14, 0x3C, 0xFF);
	draw_player(data, data->player.x * 10, data->player.y * 10, color);
}
