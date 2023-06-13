/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:50:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 18:12:03 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stack *s1, t_stack *s2)
{
	t_node	*node;

	node = s1->stack;
	s1->stack = s1->stack->next;
	node->idx = 0;
	node->next = NULL;
	if (!s2->size)
		s2->stack = node;
	else
	{
		node->idx = s2->stack->idx + 1;
		node->next = s2->stack;
		s2->stack = node;
	}
	s2->size += 1;
	s1->size -= 1;
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size)
		push(b, a);
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size)
		push(a, b);
	printf("pb\n");
}
