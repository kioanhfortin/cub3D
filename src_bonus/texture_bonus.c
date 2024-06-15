/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:42 by seroy             #+#    #+#             */
/*   Updated: 2024/05/20 16:55:36 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

uint32_t	**ft_buf_line_text(t_data *data, mlx_texture_t *tex_Wall_R,
		uint32_t **buf)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 0;
	buf = malloc(sizeof(uint32_t *) * (TEX_HEIGHT));
	ft_safety(buf, data);
	while (y < TEX_HEIGHT)
	{
		buf[y] = malloc(sizeof(uint32_t) * (TEX_WIDTH));
		ft_safety_small(buf, y, data);
		x = 0;
		while (x < TEX_WIDTH)
		{
			i = (y * tex_Wall_R->width * 4) + (x * 4);
			buf[y][x] = get_rgba(tex_Wall_R->pixels[i], tex_Wall_R->pixels[i
					+ 1], tex_Wall_R->pixels[i + 2], tex_Wall_R->pixels[i + 3]);
			x++;
		}
		y++;
	}
	return (buf);
}

mlx_texture_t *ft_random_cat_tex()
{
	int i;
	char *str;

	i = (rand() % 10);
	str = "wallTexture/Black_100/tex_B_100_0";
	str = ft_strjoin(str, ft_itoa(i));
	str = ft_strjoin(str, ".png");
	return (mlx_load_png(str));
}

void	ft_load_texture(t_data *data)
{
	set_player_angle(data);
	data->tex_wall_n = mlx_load_png(data->path[NORTH]);
	if (data->tex_wall_n == NULL)
		error_texture(data);
	data->tex_wall_s = mlx_load_png(data->path[SOUTH]);
	if (data->tex_wall_s == NULL)
		error_texture(data);
	data->tex_wall_e = mlx_load_png(data->path[EAST]);
	if (data->tex_wall_e == NULL)
		error_texture(data);
	data->tex_wall_o = mlx_load_png(data->path[WEST]);
	if (data->tex_wall_o == NULL)
		error_texture(data);
	data->tex_wall_cat = ft_random_cat_tex();
	if (data->tex_wall_o == NULL)
		error_texture(data);
	ft_fill_bufs(data);
}

void	ft_fill_bufs(t_data *data)
{
	if (ft_check_oversize_tex(data) == 1)
	{
		data->n_buf = ft_buf_line_text(data, data->tex_wall_n, data->n_buf);
		data->s_buf = ft_buf_line_text(data, data->tex_wall_s, data->s_buf);
		data->e_buf = ft_buf_line_text(data, data->tex_wall_e, data->e_buf);
		data->o_buf = ft_buf_line_text(data, data->tex_wall_o, data->o_buf);
		data->cat_buf = ft_buf_line_text(data, data->tex_wall_cat, data->cat_buf);
	}
	else
	{
		data->n_buf = ft_resize_tex(data, data->tex_wall_n, data->n_buf);
		data->s_buf = ft_resize_tex(data, data->tex_wall_s, data->s_buf);
		data->e_buf = ft_resize_tex(data, data->tex_wall_e, data->e_buf);
		data->o_buf = ft_resize_tex(data, data->tex_wall_o, data->o_buf);
		data->cat_buf = ft_resize_tex(data, data->tex_wall_cat, data->cat_buf);
	}
}

int	ft_check_oversize_tex(t_data *data)
{
	if ((data->tex_wall_n->height == 100 && data->tex_wall_n->width == 100)
		&& (data->tex_wall_s->height == 100 && data->tex_wall_s->width == 100)
		&& (data->tex_wall_e->height == 100 && data->tex_wall_e->width == 100)
		&& (data->tex_wall_o->height == 100 && data->tex_wall_o->width == 100))
		return (1);
	return (0);
}

void	ft_get_texture(t_data *data, t_line *line, uint32_t **buf, int buf_x)
{
	int		buf_y;
	int		j;
	float	prop;

	j = line->y0;
	prop = ((float)TEX_WIDTH / data->ray->h_wall);
	while (j < line->y1)
	{
		buf_y = (j - line->y0) * prop;
		if (buf_y >= 0 && buf_y < TEX_HEIGHT && buf_x >= 0 && buf_x < TEX_WIDTH
			&& ft_check_frame(line->x, j) == 0)
			mlx_put_pixel(data->img[0], line->x, j, buf[buf_y][buf_x]);
		j++;
	}
}
