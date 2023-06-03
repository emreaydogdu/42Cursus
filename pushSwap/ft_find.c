/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:17:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/01 23:26:00 by emaydogd         ###   ########.fr       */
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

t_node	*ft_find_next(int val, t_stack a)
{
	t_node	*next;

	next = a.stack;
	while (a.stack->next)
	{
		if (a.stack->val > val)
		{
			if (ft_abs(a.stack->val - val) < ft_abs(next->val - val))
				next = a.stack;
		}
		a.stack = a.stack->next;
	}
	return (next);
}

t_node	*ft_find_prev(int val, t_stack a)
{
	t_node	*prev;

	prev = a.stack;
	while (a.stack->next)
	{
		if (a.stack->val < val)
		{
			if (ft_abs(a.stack->val - val) <= ft_abs(prev->val - val))
				prev = a.stack;
		}
		a.stack = a.stack->next;
	}
	return (prev);
}
