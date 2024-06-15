/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:43 by seroy             #+#    #+#             */
/*   Updated: 2024/05/20 17:05:47 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	show_minimap(t_data *data)
{
	if (data->img[1]->instances[0].z >= 0)
	{
		data->img[1]->instances[0].z = -1;
		data->img[2]->instances[0].z = -1;
		data->minimap_satus = -1;
	}
	else
	{
		data->img[1]->instances[0].z = 1;
		data->img[2]->instances[0].z = 2;
		data->minimap_satus = 2;
	}
}

void	re_img(t_data *data)
{
	ft_floor_sky(data);
	ft_trace_wall(data, data->ray);
}

void	mouse_hook(void *param)
{
	int32_t	x;
	int32_t	y;
	t_data	*data;

	data = param;
	mlx_get_mouse_pos(data->mlx, &x, &y);
	if (x < WINDOW_WIDTH / 2)
		rotate_left(data, (x - (WINDOW_WIDTH / 2)));
	else if (x >= WINDOW_WIDTH / 2)
		rotate_right(data, (x - (WINDOW_WIDTH / 2)));
	mlx_set_mouse_pos(data->mlx, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
	re_img(data);
}

void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_SPACE))
		mouse_hook(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move(data, NORTH);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move(data, SOUTH);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move(data, WEST);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move(data, EAST);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(data, -10);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(data, 10);
	re_img(data);
}

void	ft_option(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.key == MLX_KEY_M && keydata.action == MLX_PRESS)
		show_minimap(data);
}
