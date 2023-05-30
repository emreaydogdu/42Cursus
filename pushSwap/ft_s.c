/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:50:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/28 21:40:03 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sa(t_stack *a)
{
	int	val;

	if (a->size > 1)
	{
		val = a->stack->val;
		a->stack->val = a->stack->next->val;
		a->stack->next->val = val;
	}
	printf("sa\n");
}

void	sb(t_stack *b)
{
	int	val;

	if (b->size > 1)
	{
		val = b->stack->val;
		b->stack->val = b->stack->next->val;
		b->stack->next->val = val;
	}
	printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	//printf("ss\n");
}
