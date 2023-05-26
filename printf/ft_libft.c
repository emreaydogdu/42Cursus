/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:09:27 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/26 12:19:43 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "printf.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_callocc(size_t count, size_t size)
{
	void	*dst;
	size_t	n;

	n = count * size;
	dst = malloc(count * size);
	if (dst == NULL)
		return (NULL);
	while (n--)
		((unsigned char *)dst)[n] = (unsigned char)0;
	return (dst);
}
