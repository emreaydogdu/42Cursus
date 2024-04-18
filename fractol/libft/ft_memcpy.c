/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:53:25 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/09 12:53:26 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*b_src;
	unsigned char	*b_dest;
	size_t			i;

	if (!dest)
		return (0);
	if (!src)
		return (dest);
	i = 0;
	b_src = (unsigned char *)src;
	b_dest = (unsigned char *)dest;
	while (i < n)
	{
		b_dest[i] = b_src[i];
		i++;
	}
	b_dest = 0;
	return (dest);
}
