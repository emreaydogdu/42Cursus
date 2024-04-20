/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 23:22:06 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	ft_error(argc, argv);
	init_stack(&a, &b);
	if (argc == 2)
		ft_split_ps(argv[1], &a);
	else
		while (argc > 1)
			add_stack(&a, ft_atoi(argv[--argc]));
	ft_sort(a, b);
	free_stack(a.stack);
}
