/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:20 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/16 11:57:24 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (lst)
	{
		while (*lst)
		{
			buf = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = buf;
		}
	}
	*lst = 0;
}
