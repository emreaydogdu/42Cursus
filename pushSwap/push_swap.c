/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/28 21:40:57 by emaydogd         ###   ########.fr       */
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
		while (++i < argc)
			add_stack(&a, atoi(argv[i]));
		rrr(a, b);
		print_stack(a);
		print_stack(b);
	}
}
