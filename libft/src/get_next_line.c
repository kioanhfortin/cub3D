/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:57:00 by seroy             #+#    #+#             */
/*   Updated: 2023/03/14 13:31:34 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gfree(char *s)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (s);
}

char	*ft_gover(char *s)
{
	int		i;
	int		j;
	char	*temp;

	if (!s || ft_gstrlen(s) - ft_gstrchr(s, '\n') == 0)
	{
		free(s);
		return (NULL);
	}
	temp = ft_gcalloc((ft_gstrlen(s) - ft_gstrchr(s, '\n') + 1), sizeof(char));
	if (!temp)
	{
		free(s);
		return (NULL);
	}
	i = ft_gstrchr(s, '\n');
	j = 0;
	while (s[i])
		temp[j++] = s[i++];
	free(s);
	return (temp);
}

char	*ft_greads(int fd, int reads, char *buf, char *over)
{
	while (reads != 0 && ft_gstrchr(buf, '\n') == 0)
	{
		reads = read(fd, buf, BUFFER_SIZE);
		if (reads == -1 || BUFFER_SIZE == 0)
		{
			free(buf);
			free(over);
			over = NULL;
			return (NULL);
		}
		buf[reads] = '\0';
		over = ft_gstrjoin(over, buf);
	}
	return (over);
}

char	*ft_gnew_line(char *over)
{
	char	*line;

	line = ft_gcalloc((ft_gstrchr(over, '\n') + 1), sizeof(char));
	ft_gstrlcpy(line, over, (ft_gstrchr(over, '\n') + 1));
	return (line);
}

char	*get_next_line(int fd)
{
	t_struct		gnl;
	static char		*over;

	gnl.reads = 1;
	gnl.line = NULL;
	if (ft_gstrchr(over, '\n') != 0)
		return (gnl.line = ft_gnew_line(over), over = ft_gover(over), gnl.line);
	gnl.buf = ft_gcalloc(BUFFER_SIZE + 1, sizeof(char));
	if (!gnl.buf)
		return (ft_gfree(gnl.buf));
	over = ft_greads(fd, gnl.reads, gnl.buf, over);
	if (gnl.reads == -1 || BUFFER_SIZE == 0 || !over)
		return (NULL);
	if (ft_gstrchr(over, '\n'))
		gnl.line = ft_gcalloc((ft_gstrchr(over, '\n') + 1), sizeof(char));
	else
		gnl.line = ft_gcalloc((ft_gstrlen(over) + 1), sizeof(char));
	ft_gstrlcpy(gnl.line, over, (ft_gstrlen(over) + 1));
	free(over);
	over = ft_gover(gnl.buf);
	if (!*gnl.line)
		return (ft_gfree(gnl.line));
	return (gnl.line);
}
