/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:12 by seroy             #+#    #+#             */
/*   Updated: 2024/04/22 15:23:13 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_data(t_data *data)
{
	data->camerax = 0;
}

void	clean_line(t_line *line)
{
	line->x0 = 0;
	line->x1 = 0;
	line->y0 = 0;
	line->y1 = 0;
	line->wall_x = 0;
}

void	clean_ray(t_ray *ray)
{
	ray->side = 0;
	ray->perpwalldist = 0.0;
	ray->raydirx = 0.0;
	ray->raydiry = 0.0;
	ray->deltadistx = 0;
	ray->deltadisty = 0;
	ray->sidedistx = 0;
	ray->sidedisty = 0;
	ray->curr_x = 0;
	ray->mapx = 0;
	ray->mapy = 0;
	ray->stepx = 0;
	ray->stepy = 0;
	ray->h_wall = 0;
}
