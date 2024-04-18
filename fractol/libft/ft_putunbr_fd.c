/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:09:11 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/30 14:20:10 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lenght(unsigned int n)
{
	size_t	counter;

	counter = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		counter++;
	}
	return (counter);
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	char			ans[12];
	int				len;
	int				size;

	size = 0;
	len = lenght(n);
	ans[len--] = 0;
	while (len >= 0)
	{
		ans[len--] = (n % 10) + '0';
		n /= 10;
		if (n == 0)
			break ;
		size++;
	}
	ft_putstr_fd((char *)ans, fd);
	return (size + 1);
}
