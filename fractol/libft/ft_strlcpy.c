/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 12:23:17 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/16 12:23:18 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!ft_strlen(src))
	{
		dst[0] = '\0';
		return (0);
	}
	while (i < size && ft_strlen(dst) - i + 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i - 1] = '\0';
	return (ft_strlen(src));
}
