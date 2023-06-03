/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:19:52 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/01 13:29:32 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	init_stack(t_stack *stack)
{
	stack->empty = 1;
	stack->size = 0;
}

void	print_stack(t_stack stack)
{
	int	size;

	size = stack.size;
	printf("[Print Stack: %d]\n", size);
	while (size--)
	{
		printf("[%3d]\tidx[%3d]\n", stack.stack->val, stack.stack->idx);
		stack.stack = stack.stack->next;
	}
	printf("\n");
}

void	add_stack(t_stack *stack, int val)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return ;
	node->idx = 0;
	node->val = val;
	node->next = NULL;
	if (stack->empty)
		stack->stack = node;
	else
	{
		node->idx = stack->stack->idx + 1;
		node->next = stack->stack;
		stack->stack = node;
	}
	stack->empty = 0;
	stack->size += 1;
}

void	rm_stack(t_stack *stack)
{
	if (stack->size > 0)
	{
		if (stack->size == 1)
			stack->empty = 1;
		stack->size--;
		stack->stack = stack->stack->next;
	}
}
