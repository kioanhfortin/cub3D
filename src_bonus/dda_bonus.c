/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:48:55 by kfortin           #+#    #+#             */
/*   Updated: 2024/05/20 18:02:49 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_trace_wall(t_data *data, t_ray *ray)
{
	ray->line->tex_x = TEX_WIDTH;
	ray->line->x = 0;
	while (ray->line->x < WINDOW_WIDTH)
	{
		ft_dda(data, ray);
		ray->h_wall = (int)(WINDOW_HEIGHT / ray->perpwalldist);
		ray->line->y0 = -ray->h_wall / 2 + WINDOW_HEIGHT / 2;
		if (ray->line->y0 < 0)
			ray->line->y0 += 0;
		ray->line->y1 = ray->h_wall / 2 + WINDOW_HEIGHT / 2;
		if (ray->line->y1 >= WINDOW_HEIGHT)
			ray->line->y1 += WINDOW_HEIGHT - 1;
		trace_line(data, ray->line);
		ft_cat_sound(data);
		ray->line->x++;
		clean_data(data);
		clean_line(ray->line);
	}
}

void	trace_line(t_data *data, t_line *line)
{
	int	buf_x;

	buf_x = 0;
	if (data->map[(int)data->ray->mapy][(int)data->ray->mapx] == '2')
	{
		buf_x = get_hit(data, data->tex_wall_cat);
		ft_get_texture(data, line, data->cat_buf, buf_x);
	}
	else
	{
		if (data->ray->side == 1)
		{
			buf_x = get_hit(data, data->tex_wall_s);
			ft_get_texture(data, line, data->s_buf, buf_x);
		}
		else if (data->ray->side == 2)
		{
			buf_x = get_hit2(data, data->tex_wall_o);
			ft_get_texture(data, line, data->o_buf, buf_x);
		}
		else if (data->ray->side == 3)
		{
			buf_x = get_hit(data, data->tex_wall_n);
			ft_get_texture(data, line, data->n_buf, buf_x);
		}
		else
		{
			buf_x = get_hit2(data, data->tex_wall_e);
			ft_get_texture(data, line, data->e_buf, buf_x);
		}
	}
}

int	get_hit(t_data *data, mlx_texture_t *tex_Wall)
{
	double	hit;
	int		buf_x;

	(void)tex_Wall;
	hit = data->ray->perpwalldist;
	hit = data->player.x + hit * data->ray->raydirx;
	hit = data->ray->perpwalldist * data->ray->raydirx + data->player.x;
	hit -= floor(hit);
	buf_x = (int)(hit * (double)TEX_WIDTH);
	if (data->ray->side % 2 == 0 && data->ray->raydirx < 0)
		buf_x = TEX_WIDTH - buf_x - 1;
	else if (data->ray->side % 2 != 0 && data->ray->raydiry < 0)
		buf_x = TEX_WIDTH - buf_x - 1;
	return (buf_x);
}

int	get_hit2(t_data *data, mlx_texture_t *tex_Wall)
{
	double	hit;
	int		buf_x;

	(void)tex_Wall;
	hit = data->ray->perpwalldist;
	hit = data->player.y + hit * data->ray->raydiry;
	hit = data->ray->perpwalldist * data->ray->raydiry + data->player.y;
	hit -= floor(hit);
	buf_x = (int)(hit * (double)TEX_WIDTH);
	if (data->ray->side % 2 == 0 && data->ray->raydirx > 0)
		buf_x = TEX_WIDTH - buf_x - 1;
	if (data->ray->side % 2 != 0 && data->ray->raydiry < 0)
		buf_x = TEX_WIDTH - buf_x - 1;
	return (buf_x);
}
