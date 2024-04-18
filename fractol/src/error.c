/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <emaydogd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:07:37 by emaydogd          #+#    #+#             */
/*   Updated: 2024/04/18 17:15:05 by emaydogd         ###   ########.fr       */
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
