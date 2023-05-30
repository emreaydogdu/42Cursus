/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:55:35 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/29 14:38:29 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	rra(t_stack a)
{
	t_stack	tmp;
	int		val;
	int		val2;

	if (a.size > 1)
	{
		tmp.stack = a.stack;
		while (tmp.stack->next)
			tmp.stack = tmp.stack->next;
		val = a.stack->val;
		a.stack->val = tmp.stack->val;
		while (a.stack->next)
		{
			val2 = a.stack->next->val;
			a.stack->next->val = val;
			val = val2;
			a.stack = a.stack->next;
		}
	}
	printf("rra\n");
}

void	rrb(t_stack b)
{
	t_stack	tmp;
	int		val;
	int		val2;

	if (b.size > 1)
	{
		tmp.stack = b.stack;
		while (tmp.stack->next)
			tmp.stack = tmp.stack->next;
		val = b.stack->val;
		b.stack->val = tmp.stack->val;
		while (b.stack->next)
		{
			val2 = b.stack->next->val;
			b.stack->next->val = val;
			val = val2;
			b.stack = b.stack->next;
		}
	}
	printf("rrb\n");
}

void	rrr(t_stack a, t_stack b)
{
	rra(a);
	rrb(b);
	//printf("rrr\n");
}
