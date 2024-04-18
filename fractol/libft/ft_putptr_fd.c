/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_fd.c		                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:00:43 by fzucconi          #+#    #+#             */
/*   Updated: 2023/11/22 19:46:16 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr_fd(unsigned long int nb, int fd)
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
