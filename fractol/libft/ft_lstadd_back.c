/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:55:14 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/16 11:55:19 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*new_list;

	if (!new)
		return ;
	if (!lst || !*lst)
		*lst = new;
	else
	{
		new_list = *lst;
		while (new_list->next)
			new_list = new_list->next;
		new_list->next = new;
	}
}
