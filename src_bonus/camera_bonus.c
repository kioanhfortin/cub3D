/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:48:50 by kfortin           #+#    #+#             */
/*   Updated: 2024/04/30 19:26:38 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

double	ft_deg_rad(int deg)
{
	double	rad;

	rad = deg * M_PI / 180.0;
	return (rad);
}

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}
