/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <fzucconi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:57:57 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/12 13:46:24 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;

	i = 0;
	if (len == 0)
	{
		if (!ft_strncmp(to_find, "", 1))
			return ((char *)str);
		else
			return (0);
	}
	if (str == to_find)
		return ((char *)str);
	if (len < ft_strlen(to_find) || (!ft_strncmp(str, "", 1)))
		return (0);
	if (to_find[0] == '\0')
		return ((char *)str);
	i = 0;
	while (i <= (len - ft_strlen(to_find)))
	{
		if ((str[i] == to_find[0])
			&& (!ft_strncmp(&str[i], to_find, ft_strlen(to_find))))
			return ((char *)(&str[i]));
		i++;
	}
	return (0);
}
