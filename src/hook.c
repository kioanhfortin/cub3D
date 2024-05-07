/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:43 by seroy             #+#    #+#             */
/*   Updated: 2024/05/01 12:33:53 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
