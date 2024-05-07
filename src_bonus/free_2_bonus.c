/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:39 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:27:42 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ft_safety(uint32_t **buf, t_data *data)
{
	if (!buf)
	{
		if (buf)
			free(buf);
		ft_free(data);
		exit(1);
	}
}

void	ft_safety_small(uint32_t **buf, int y, t_data *data)
{
	int	j;

	j = 0;
	if (!buf[y])
	{
		while (j < y)
		{
			if (buf[j])
				free(buf[j]);
			j++;
		}
		if (buf)
			free(buf);
		ft_free(data);
		exit(1);
	}
}

void	free_close(int fd, t_data *data)
{
	close(fd);
	ft_free(data);
}

void	ft_safety_small_2(char **buf, int y, t_data *data)
{
	int	j;

	j = 0;
	if (!buf[y])
	{
		while (j < y)
		{
			if (buf[j])
				free(buf[j]);
			j++;
		}
		if (buf)
			free(buf);
		ft_free(data);
		exit(1);
	}
}
