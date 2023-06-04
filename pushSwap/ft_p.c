/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:50:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/02 00:07:40 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	if (!b->empty)
	{
		add_stack(a, b->stack->val);
		rm_stack(b);
	}
	printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->empty)
	{
		add_stack(b, a->stack->val);
		rm_stack(a);
	}
	printf("pb\n");
}
