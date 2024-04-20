/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:50:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/04 14:23:40 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	r(t_stack s)
{
	int	val;

	if (s.size > 1)
	{
		val = s.stack->val;
		while (s.stack->next)
		{
			s.stack->val = s.stack->next->val;
			s.stack = s.stack->next;
		}
		s.stack->val = val;
	}
}

void	ra(t_stack a)
{
	r(a);
	printf("ra\n");
}

void	rb(t_stack b)
{
	r(b);
	printf("rb\n");
}

void	rr(t_stack a, t_stack b)
{
	r(a);
	r(b);
	printf("rr\n");
}
