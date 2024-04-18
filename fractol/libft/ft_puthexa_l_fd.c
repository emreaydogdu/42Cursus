/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_l_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:31:30 by fzucconi          #+#    #+#             */
/*   Updated: 2023/11/22 19:46:18 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

int	ft_puthexa_l_fd(unsigned int nb, int fd)
{
	char	hex_revert[16];
	int		i;
	int		ret;

	ft_bzero(hex_revert, 16);
	i = 0;
	while (nb)
	{
		if ((nb % 16) >= 10)
			hex_revert[i] = (nb % 16) + 'a' - 10;
		else
			hex_revert[i] = (nb % 16) + '0';
		nb /= 16;
		if (nb == 0)
			break ;
		i++;
	}
	ret = i;
	while (i >= 0)
	{
		ft_putchar_fd(hex_revert[i], fd);
		i--;
	}
	return (ret + 1);
}
