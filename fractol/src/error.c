/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:25:12 by fzucconi          #+#    #+#             */
/*   Updated: 2023/12/06 14:06:09 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fractol.h"
void	ft_error(char *msg, int ins)
{
	ft_printf("%s\n", msg);
	if (ins)
		ft_printf("%s", INSTRUCTIONS);
	exit(EXIT_FAILURE);
}