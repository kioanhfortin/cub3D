/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:53:34 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 14:52:20 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	na;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
	}
	else
	{
		if (n >= 0 && n < 10)
		{
			na = n + 48;
			write(fd, &na, 1);
		}
		else if (n < 0)
		{
			write(fd, "-", 1);
			ft_putnbr_fd(-n, fd);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
