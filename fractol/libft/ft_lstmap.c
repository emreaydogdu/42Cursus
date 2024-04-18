/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:55:48 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/16 11:55:53 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*n_list;
	void	*val;

	if (!lst || !f || !del)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		val = f(lst->content);
		n_list = ft_lstnew(val);
		if (!n_list)
		{
			del(val);
			ft_lstclear(&ret, (*del));
			return (ret);
		}
		ft_lstadd_back(&ret, n_list);
		lst = lst->next;
	}
	return (ret);
}
