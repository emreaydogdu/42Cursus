/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:19:52 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/12 16:36:39 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	free_stack(t_node *s)
{
	if (s->next)
		free_stack(s->next);
	free(s);
}

void	init_stack(t_stack *a, t_stack *b)
{
	a->empty = 1;
	a->size = 0;
	b->empty = 1;
	b->size = 0;
}

void	print_stack(t_stack stack)
{
	int	size;
	int	i;

	i = 0;
	size = stack.size;
	printf("[Print Stack: %d]\n", size);
	while (i++ < size - 1)
	{
		printf("[%3d]\tidx[%3d]\n", stack.stack->val, stack.stack->idx);
		stack.stack = stack.stack->next;
	}
	if (size)
		printf("[%3d]\tidx[%3d]\n", stack.stack->val, stack.stack->idx);
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
	t_node	*next;

	if (stack->size > 0)
	{
		if (stack->size == 1)
			stack->empty = 1;
		stack->size--;
		next = stack->stack->next;
		free(stack->stack);
		stack->stack = next;
	}
}
