/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 00:02:50 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 21:11:14 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_lstlen(const int *lst)
{
	int	len;

	len = 0;
	while (lst[len] && lst[len] != -1)
		len++;
	return (len);
}

void	ft_lstreset(int *lst)
{
	int	i;
	int	len;

	i = 0;
	len = ft_lstlen(lst);
	while (i < len)
	{
		lst[i] = 0;
		i++;
	}
}

void	ft_lstbest(int *list, int *best)
{
	int	len;
	int	j;

	len = ft_lstlen(list);
	if (!ft_lstlen(best) || len < ft_lstlen(best))
	{
		ft_lstreset(best);
		j = 0;
		while (j < len)
		{
			best[j] = list[j];
			j++;
		}
	}
}
