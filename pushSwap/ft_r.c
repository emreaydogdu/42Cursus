/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:50:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/28 21:52:46 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ra(t_stack a)
{
	int	val;

	if (a.size > 1)
	{
		val = a.stack->val;
		while (a.stack->next)
		{
			a.stack->val = a.stack->next->val;
			a.stack = a.stack->next;
		}
		a.stack->val = val;
	}
}

void	rb(t_stack b)
{
	int	val;

	if (b.size > 1)
	{
		val = b.stack->val;
		while (b.stack->next)
		{
			b.stack->val = b.stack->next->val;
			b.stack = b.stack->next;
		}
		b.stack->val = val;
	}
}

void	rr(t_stack a, t_stack b)
{
	ra(a);
	rb(b);
}
