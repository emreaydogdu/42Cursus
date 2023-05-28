/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:50:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/28 21:35:59 by emaydogd         ###   ########.fr       */
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
}

void	pb(t_stack *a, t_stack *b)
{
	if (!a->empty)
	{
		add_stack(b, a->stack->val);
		rm_stack(a);
	}

}
