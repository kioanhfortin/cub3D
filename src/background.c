/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:22:33 by seroy             #+#    #+#             */
/*   Updated: 2024/04/22 15:31:04 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_gradient(t_data *data, int y, int x)
{
	int		mix_color[3];
	double	t;

	t = (double)y / WINDOW_HEIGHT;
	mix_color[0] = (int)((1 - t) * data->ceiling[0] + t * data->floor[0]);
	mix_color[1] = (int)((1 - t) * data->ceiling[1] + t * data->floor[1]);
	mix_color[2] = (int)((1 - t) * data->ceiling[2] + t * data->floor[2]);
	if (ft_check_frame(x, y) == 0)
		mlx_put_pixel(data->img[0], x, y, get_rgba(mix_color[0], mix_color[1],
				mix_color[2], 255));
}

int	ft_check_frame(int x, int y)
{
	if (x < WINDOW_WIDTH && y < WINDOW_HEIGHT && y >= 0 && x >= 0)
		return (0);
	return (1);
}

void	ft_floor_sky(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			ft_gradient(data, y, x);
			x++;
		}
		y++;
	}
}
