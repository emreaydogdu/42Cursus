/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 23:17:45 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/10 18:52:06 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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
	int		curr;
	t_node	*next;

	curr = INT_MAX;
	while (s.stack)
	{
		if (s.stack->val > val)
		{
			if (ft_abs(s.stack->val - val) < ft_abs(curr - val))
			{
				next = s.stack;
				curr = s.stack->val;
			}
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

void	ft_rotate_end(t_stack a, t_stack b)
{
	t_node	*max;
	int		k;

	max = ft_find_max(b);
	if (ft_abs(b.size - 1 - max->idx) <= max->idx + 1)
	{
		k = max->idx;
		while (k++ < b.size - 1)
			rb(b);
	}
	else
	{
		k = max->idx;
		while (k-- > 0)
			rrb(b);
		rrb(b);
	}
	while (b.size)
		pa(&a, &b);
	print_stack(a);
}
