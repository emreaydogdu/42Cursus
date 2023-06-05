/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/05 01:40:07 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_split(char *args, t_stack *a)
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

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc > 1)
	{
		init_stack(&a);
		init_stack(&b);
		if (argc == 2)
		{
			ft_split(argv[1], &a);
		}
		else
		{
			while (argc > 1)
				add_stack(&a, atoi(argv[--argc]));
		}
		ft_sort(a, b);
		//print_stack(a);
	}
/*
	int *best;
	best = malloc(sizeof(int) * 1000);
	if (!best)
		return 0;
	best[0] = RA;
	best[1] = RA;
	best[2] = RA;
	best[3] = RB;
	best[4] = RB;
	best[5] = PA;
	ft_lstprint(best);
	ft_lstoptimize(best);
*/
}
