/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:42:58 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/09 18:48:26 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_place_new_min(t_stack b, int *lst, int j)
{
	t_node	*min;
	int		k;

	min = ft_find_min(b);
	if (ft_abs(b.size - 1 - min->idx) + 1 <= min->idx)
	{
		k = min->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
		lst[j++] = RB;
	}
	else
	{
		k = min->idx;
		while (k-- > 0)
			lst[j++] = RRB;
	}
	lst[j++] = PB;
}

void	ft_place_new_max(t_stack b, int *lst, int j)
{
	t_node	*max;
	int		k;

	max = ft_find_max(b);
	if (ft_abs(b.size - 1 - max->idx) <= max->idx + 1)
	{
		k = max->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
	}
	else
	{
		k = max->idx;
		while (k-- > 0)
			lst[j++] = RRB;
		lst[j++] = RRB;
	}
	lst[j++] = PB;
}

void	ft_check_min(t_stack b, int val, int *lst, int j)
{
	t_node	*prev;
	int		k;

	prev = ft_find_prev(val, b);
	if (ft_abs(b.size - 1 - prev->idx) <= prev->idx + 1)
	{
		k = prev->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
	}
	else
	{
		k = prev->idx;
		while (k-- > 0)
			lst[j++] = RRB;
		lst[j++] = RRB;
	}
	lst[j++] = PB;
}

void	ft_check_max(t_stack b, int val, int *lst, int j)
{
	t_node	*next;
	int		k;

	next = ft_find_next(val, b);
	if (ft_abs(b.size - 1 - next->idx) <= next->idx + 1)
	{
		k = next->idx;
		while (k++ < b.size - 1)
			lst[j++] = RB;
		lst[j++] = RB;
	}
	else
	{
		k = next->idx;
		while (k-- > 0)
			lst[j++] = RRB;
	}
	lst[j++] = PB;
}

//ft_check_max(b, val, lst, j);
int	*ft_place_new_middle(t_stack b, int val, int *lst, int j)
{
	ft_check_min(b, val, lst, j);
	return (lst);
}
