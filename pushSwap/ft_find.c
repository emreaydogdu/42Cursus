/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:17:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 00:05:12 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_abs(int val)
{
	if (val < 0)
		return (val * -1);
	return (val);
}

t_node	*ft_find_min(t_stack a)
{
	t_node	*min_idx;

	min_idx = a.stack;
	while (a.stack->next)
	{
		if (a.stack->val < min_idx->val)
			min_idx = a.stack;
		a.stack = a.stack->next;
	}
	if (a.stack->val < min_idx->val)
		min_idx = a.stack;
	return (min_idx);
}

t_node	*ft_find_max(t_stack a)
{
	t_node	*max_idx;

	max_idx = a.stack;
	while (a.stack->next)
	{
		if (a.stack->val > max_idx->val)
			max_idx = a.stack;
		a.stack = a.stack->next;
	}
	if (a.stack->val > max_idx->val)
		max_idx = a.stack;
	return (max_idx);
}

t_node	*ft_find_next(int val, t_stack s)
{
	t_node	*next;

	while (s.stack)
	{
		if (s.stack->val > val)
		{
			if (!next || ft_abs(s.stack->val - val) < ft_abs(next->val - val))
				next = s.stack;
		}
		s.stack = s.stack->next;
	}
	return (next);
}

t_node	*ft_find_prev(int val, t_stack s)
{
	int		curr;
	t_node	*prev;

	curr = INT_MIN;
	while (s.stack)
	{
		if (s.stack->val < val)
		{
			if (ft_abs(val - s.stack->val) < ft_abs(val - curr))
			{
				prev = s.stack;
				curr = s.stack->val;
			}
		}
		s.stack = s.stack->next;
	}
	return (prev);
}

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
