/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:55:35 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 00:09:12 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	rrab(t_stack s)
{
	t_stack	tmp;
	int		val;
	int		val2;

	if (s.size > 1)
	{
		tmp.stack = s.stack;
		while (tmp.stack->next)
			tmp.stack = tmp.stack->next;
		val = s.stack->val;
		s.stack->val = tmp.stack->val;
		while (s.stack->next)
		{
			val2 = s.stack->next->val;
			s.stack->next->val = val;
			val = val2;
			s.stack = s.stack->next;
		}
	}
}

void	rra(t_stack a)
{
	rrab(a);
	printf("rra\n");
}

void	rrb(t_stack b)
{
	rrab(b);
	printf("rrb\n");
}

void	rrr(t_stack a, t_stack b)
{
	rrab(a);
	rrab(b);
	printf("rrr\n");
}
