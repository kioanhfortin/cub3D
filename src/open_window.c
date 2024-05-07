/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:24:34 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 17:38:05 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_data *data)
{
	int	i;

	i = 0;
	data->mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (ft_exit_failure(data));
	while (i < 3)
	{
		data->img[i] = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		if (!(data->img[i]))
			return (ft_exit_failure(data));
		if (mlx_image_to_window(data->mlx, data->img[i], 0, 0) == -1)
			return (ft_exit_failure(data));
		i++;
	}
	return (0);
}

int	ft_exit_failure(t_data *data)
{
	mlx_close_window(data->mlx);
	puts(mlx_strerror(mlx_errno));
	ft_free(data);
	return (1);
}
