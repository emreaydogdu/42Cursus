/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:26:27 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/10 14:04:57 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= len)
		len = s_len - start;
	if (start > s_len)
		return (ft_strdup(""));
	sub = ft_calloc(len + 1, sizeof(char));
	if (sub == NULL)
		return (NULL);
	else
		ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
