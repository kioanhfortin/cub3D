/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:23:27 by seroy             #+#    #+#             */
/*   Updated: 2024/04/30 19:27:19 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	errmessage_2(int a, char *s)
{
	if (a == 1)
		printmess(2, "Error\nWrong number of objects");
	if (a == 2)
	{
		printmess(2, "Error\nThere are two existing paths for ");
		printmess(2, s);
	}
	if (a == 4)
	{
		printmess(2, "Error\nMissing path for one of the 4 directions");
		printmess(2, "of color for Floor/Ceiling");
	}
	if (a == 5)
		printmess(2, "Error\nMap is not a .cub extension");
	if (a == 6)
	{
		printmess(2, "Error\nFile ");
		printmess(2, s);
		printmess(2, " does not exist..!");
	}
}

void	errmessage_3(int a, char *s)
{
	if (a == 7)
	{
		printmess(2, "Error\nUnknown object detected in map file -> ");
		printmess(2, s);
	}
	if (a == 8)
		printmess(2, "Error\nMissing arguments");
	if (a == 9)
		printmess(2, "Error\nToo many arguments");
	if (a == 10)
		printmess(2, "Error\nNo map found..!");
	if (a == 11)
	{
		printmess(2, "Error\nColor value incorrect..!");
		free(s);
	}
}

int	errmessage(int a, char *s, t_data *data)
{
	errmessage_2(a, s);
	errmessage_3(a, s);
	if (a == 12)
		printmess(2, "Error\nTwo or more starting direction found..!");
	if (a == 13)
		printmess(2,
			"Error\nThere is an empty space that shouldn't be there..!");
	if (a == 14)
		printmess(2, "Error\nMissing element(s) in map..!");
	if (a == 15)
		printmess(2, "Error\nFile is empty..!");
	if (a == 16)
		printmess(2, "Error\nEmpty line in map");
	if (data)
		ft_free(data);
	exit(1);
}

void	error_texture(t_data *data)
{
	perror("Erreur lors du chargement de la texture");
	ft_free(data);
	exit(1);
}
