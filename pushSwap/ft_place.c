/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:42:58 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 21:43:41 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_place_new_min(t_stack b, int *lst, int j)
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

static void	ft_place_new_max(t_stack b, int *lst, int j)
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

static void	ft_check_min(t_stack b, int val, int *lst, int j)
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

void	ft_calc_a(t_stack *a, t_node *val, int i, int *j)
{
	if (a->size - 1 - i >= a->size / 2)
	{
		while ((*j) != i && i != a->size - 1)
			val->lst[(*j)++] = RA;
	}
	else
	{
		while (a->size - 1 - i - (*j) != 0)
			val->lst[(*j)++] = RRA;
		val->lst[(*j)++] = RRA;
	}
}

void	ft_calc_b(t_stack *b, int *best, t_node *val, int j)
{
	if (val->val < ft_find_min(*b)->val)
		ft_place_new_min(*b, val->lst, j);
	else if (val->val > ft_find_max(*b)->val)
		ft_place_new_max(*b, val->lst, j);
	else
		ft_check_min(*b, val->val, val->lst, j);
	ft_optimize(val->lst);
	ft_lstbest(val->lst, best);
	free(val->lst);
}
