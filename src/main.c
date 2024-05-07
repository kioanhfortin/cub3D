/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:50 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:45:12 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	data;

	ft_file_format(argc, argv[1]);
	init_struct(&data);
	ft_read_file(&data, argv);
	if (!ver_data(&data))
		ft_free(&data);
	init_mlx(&data);
	ft_floor_sky(&data);
	ft_load_texture(&data);
	ft_trace_wall(&data, data.ray);
	mlx_set_cursor_mode(data.mlx, 0x00034002);
	mlx_loop_hook(data.mlx, &ft_hook, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	ft_free(&data);
	return (EXIT_SUCCESS);
}
