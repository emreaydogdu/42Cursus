/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 14:19:52 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 21:44:40 by emaydogd         ###   ########.fr       */
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
	a->size = 0;
	b->size = 0;
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
	if (!stack->size)
		stack->stack = node;
	else
	{
		node->idx = stack->stack->idx + 1;
		node->next = stack->stack;
		stack->stack = node;
	}
	stack->size += 1;
}

t_node	*get_stack(t_stack a, int i)
{
	while (i--)
		a.stack = a.stack->next;
	return (a.stack);
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
