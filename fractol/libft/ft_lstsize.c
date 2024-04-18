/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:58:14 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/16 11:58:16 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		counter;
	t_list	*buf;

	counter = 0;
	buf = lst;
	if (buf)
	{
		while (buf)
		{
			buf = buf->next;
			counter++;
		}
	}
	return (counter);
}
