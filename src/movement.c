/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:32 by seroy             #+#    #+#             */
/*   Updated: 2024/05/01 12:12:45 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_data *data, int32_t x)
{
	double	old_dirx;
	double	old_planex;

	x *= 0.1;
	old_dirx = data->dirx;
	old_planex = data->planex;
	data->dirx = data->dirx * cos(-0.01 * x) - data->diry * sin(-0.01 * x);
	data->diry = old_dirx * sin(-0.01 * x) + data->diry * cos(-0.01 * x);
	data->planex = data->planex * cos(-0.01 * x) - data->planey * sin(-0.01
			* x);
	data->planey = old_planex * sin(-0.01 * x) + data->planey * cos(-0.01 * x);
}

void	rotate_left(t_data *data, int32_t x)
{
	double	old_dirx;
	double	old_planex;

	x *= -0.1;
	old_dirx = data->dirx;
	old_planex = data->planex;
	data->dirx = data->dirx * cos(0.01 * x) - data->diry * sin(0.01 * x);
	data->diry = old_dirx * sin(0.01 * x) + data->diry * cos(0.01 * x);
	data->planex = data->planex * cos(0.01 * x) - data->planey * sin(0.01 * x);
	data->planey = old_planex * sin(0.01 * x) + data->planey * cos(0.01 * x);
}
