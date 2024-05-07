/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:30 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:28:45 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move(t_data *data, int dir)
{
	reset_player_minimap(data);
	if (dir == NORTH)
		move_1(data);
	else if (dir == SOUTH)
		move_2(data);
	else if (dir == WEST)
		move_3(data);
	else if (dir == EAST)
		move_4(data);
	draw_player(data, data->player.x * 10, data->player.y * 10, ft_pixel(0xDC,
			0x14, 0x3C, 0xFF));
}

void	move_1(t_data *data)
{
	if (data->map[(int)(data->player.y + (data->diry
				* SPEED))][(int)data->player.x] != '1')
		data->player.y += data->diry * SPEED;
	if (data->map[(int)(data->player.y)][(int)((data->player.x) + (data->dirx
				* SPEED))] != '1')
		data->player.x += data->dirx * SPEED;
}

void	move_2(t_data *data)
{
	if (data->map[(int)(data->player.y - (data->diry
				* SPEED))][(int)data->player.x] != '1')
		data->player.y -= data->diry * SPEED;
	if (data->map[(int)(data->player.y)][(int)((data->player.x) - (data->dirx
				* SPEED))] != '1')
		data->player.x -= data->dirx * SPEED;
}

void	move_3(t_data *data)
{
	if (data->map[(int)(data->player.y - (data->planey
				* SPEED))][(int)data->player.x] != '1')
		data->player.y -= data->planey * SPEED;
	if (data->map[(int)(data->player.y)][(int)((data->player.x) - (data->planex
				* SPEED))] != '1')
		data->player.x -= data->planex * SPEED;
}

void	move_4(t_data *data)
{
	if (data->map[(int)(data->player.y + (data->planey
				* SPEED))][(int)data->player.x] != '1')
		data->player.y += data->planey * SPEED;
	if (data->map[(int)(data->player.y)][(int)((data->player.x) + (data->planex
				* SPEED))] != '1')
		data->player.x += data->planex * SPEED;
}
