/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:16:58 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 16:52:58 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newl;
	t_list	*new;
	void	*temp;

	newl = 0;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		new = ft_lstnew(temp);
		if (!new)
		{
			ft_lstclear(&new, del);
			free (temp);
		}
		ft_lstadd_back(&newl, new);
		lst = lst->next;
	}
	return (newl);
}
