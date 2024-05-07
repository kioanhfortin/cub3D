/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_2_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:49:26 by kfortin           #+#    #+#             */
/*   Updated: 2024/04/30 19:26:46 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_dda(t_data *data, t_ray *ray)
{
	int	hit;

	hit = 0;
	ft_rayon(data, ray);
	while (hit == 0)
	{
		ft_forward_until_hit(ray);
		if (ray->mapx >= 0 && ray->mapy <= data->height
			&& data->map[(int)ray->mapy][(int)ray->mapx] == '1')
			hit = 1;
	}
	if (ray->side % 2 == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
}

void	ft_rayon(t_data *data, t_ray *ray)
{
	ft_setup(data, ray);
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (data->player.x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - data->player.x) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (data->player.y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - data->player.y) * ray->deltadisty;
	}
}

void	ft_setup(t_data *data, t_ray *ray)
{
	data->camerax = 2 * ray->line->x / (double)WINDOW_WIDTH - 1;
	ray->raydirx = data->dirx + data->planex * data->camerax;
	ray->raydiry = data->diry + data->planey * data->camerax;
	ray->mapx = (int)data->player.x;
	ray->mapy = (int)data->player.y;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
}

void	ft_forward_until_hit(t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 4;
		if (ray->stepx == -1)
			ray->side = 2;
	}
	else
	{
		ray->sidedisty += ray->deltadisty;
		ray->mapy += ray->stepy;
		ray->side = 1;
		if (ray->stepy == -1)
			ray->side = 3;
	}
}
