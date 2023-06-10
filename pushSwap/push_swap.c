/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/10 18:11:52 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	ft_split(char *args, t_stack *a)
{
	int	val;

	val = 0;
	while (*args)
	{
		if (*args != ' ')
			val = val * 10 + *args - '0';
		else
		{
			add_stack(a, val);
			r(*a);
			val = 0;
		}
		args++;
	}
	add_stack(a, val);
	r(*a);
}

void	free_stack(t_node *s)
{
	if (s->next)
		free_stack(s->next);
	free(s);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		init_stack(&a);
		init_stack(&b);
		if (argc == 2)
			ft_split(argv[1], &a);
		else
			while (argc > 1)
				add_stack(&a, ft_atoi(argv[--argc]));
		ft_sort(a, b);
		free_stack(a.stack);
	}
	/*
	int *best;
	int *lst;

	lst = malloc(sizeof(int) * 10);
	best = malloc(sizeof(int) * 10);
	lst[0] = 1;
	lst[1] = 2;
	lst[2] = 3;
	ft_memcpy(best, lst, 3 * sizeof(int));
	lst[2] = 5;
	best[2] = 8;
	print_list(lst);
	free(lst);
	print_list(best);
	 */
}
