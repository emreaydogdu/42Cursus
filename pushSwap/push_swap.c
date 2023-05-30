/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/29 14:46:33 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		i;

	i = 0;
	if (argc > 1)
	{
		init_stack(&a);
		init_stack(&b);
		while (argc > 1)
			add_stack(&a, atoi(argv[--argc]));
		ft_sort(a, b);
	}
	/*
	int s = 3;
	printf("%d\n", 1 >> s & 1);
	printf("%d\n", 6 >> s & 1);
	printf("%d\n", 3 >> s & 1);
	 */
}
