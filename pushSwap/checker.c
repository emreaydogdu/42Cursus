/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 12:44:07 by emaydogd          #+#    #+#             */
/*   Updated: 2023/06/13 23:25:39 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	ft_check_stack(t_stack	s)
{
	int		val;
	t_stack	tmp;

	tmp = s;
	if (s.size)
	{
		val = s.stack->val;
		while (s.stack->next)
		{
			s.stack = s.stack->next;
			if (s.stack->val > val)
				val = s.stack->val;
			else
			{
				write(1, "KO\n", 3);
				free_stack(tmp.stack);
				return ;
			}
		}
		write(1, "OK\n", 3);
		free_stack(tmp.stack);
	}
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	int		i;
	char	c[4];
	t_stack	a;
	t_stack	b;

	ft_error(argc, argv);
	init_stack(&a, &b);
	if (argc == 2)
		ft_split_ps(argv[1], &a);
	else
		while (argc > 1)
			add_stack(&a, ft_atoi(argv[--argc]));
	i = -1;
	while (read(STDIN_FILENO, &c[++i], 1) > 0)
	{
		if (c[i] == '\n')
		{
			c[i] = '\0';
			ft_exec_b(c, &a, &b);
			i = -1;
		}
	}
	if (b.size != 0)
		free_stack(b.stack);
	ft_check_stack(a);
}
