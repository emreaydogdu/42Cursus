/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:18:58 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/09 16:35:40 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	t_fail(void);
void	t_succ(void);

#define ASSERT(succes) if (!(succes)) t_fail(); else t_succ();

void	t_fail(void)
{
	printf("%sKO%s  ", "\033[1m\x1B[31m", "\x1B[0m");
}
void	t_succ(void)
{
	printf("%sOK%s  ", "\033[1m\033[32m", "\x1B[0m");
}

