/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:50:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 00:10:47 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	s(t_stack *s)
{
	int	val;

	if (s->size > 1)
	{
		val = s->stack->val;
		s->stack->val = s->stack->next->val;
		s->stack->next->val = val;
	}
}

void	sa(t_stack *a)
{
	s(a);
	printf("sa\n");
}

void	sb(t_stack *b)
{

	s(b);
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	s(a);
	s(b);
	printf("ss\n");
}
