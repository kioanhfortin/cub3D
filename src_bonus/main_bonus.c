/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:50 by seroy             #+#    #+#             */
/*   Updated: 2024/05/20 18:06:35 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void ft_cat_sound(t_data *data)
{
	if (data->ray->perpwalldistcat < 1.0 && data->ray->perpwalldistcat > -1)
	{
		printf("CAT SOUND ON\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	int i;

	i = 0;
	ft_file_format(argc, argv[1]);
	init_struct(&data);
	ft_read_file(&data, argv);
	if (!ver_data(&data))
		ft_free(&data);
	init_mlx(&data);
	ft_floor_sky(&data);
	ft_load_texture(&data);
	ft_trace_wall(&data, data.ray);
	ft_put_pixel(&data);
	mlx_set_cursor_mode(data.mlx, 0x00034002);
	mlx_loop_hook(data.mlx, &ft_hook, &data);
	mlx_key_hook(data.mlx, &ft_option, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free(&data);
	return (EXIT_SUCCESS);
}
