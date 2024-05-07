/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:21:29 by seroy             #+#    #+#             */
/*   Updated: 2023/02/07 15:35:46 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*current;

	current = *lst;
	if (!lst || !del)
		return ;
	while (current)
	{
		temp = current->next;
		ft_lstdelone(current, del);
		current = temp;
	}
	*lst = NULL;
}
