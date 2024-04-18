/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:22:37 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/12 15:22:38 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*buf;

	buf = dest;
	if ((dest == src) || n == 0)
		return (dest);
	if (dest > src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
	{
		while (n--)
		{
			*(unsigned char *)dest = *(unsigned char *)src;
			dest++;
			src++;
		}
	}
	return (buf);
}
