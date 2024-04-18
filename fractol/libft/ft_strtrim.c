/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:55:20 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/12 17:55:21 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trimmmable(char to_check, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
		if (to_check == set[i++])
			return (1);
	return (0);
}

static int	trimmed_lenght(char const *s1, char const *set)
{
	int	len;
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	len = ft_strlen(s1) - 1;
	while (is_trimmmable(s1[i], set))
	{
		counter++;
		i++;
	}
	while (is_trimmmable(s1[len], set))
	{
		counter++;
		len--;
	}
	if ((int)(ft_strlen(s1) - counter) <= 0)
		return (0);
	else
		return (ft_strlen(s1) - counter);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				len;
	int				i;
	unsigned char	*ans;

	len = trimmed_lenght(s1, set);
	ans = (unsigned char *)malloc((sizeof(unsigned char) * (len + 1)));
	if (!ans)
		return (0);
	if (len == 0)
	{
		ans[0] = '\0';
		return ((char *)ans);
	}
	while (is_trimmmable(*s1, set))
		s1++;
	i = 0;
	while (i < len && s1[i])
	{
		ans[i] = (unsigned char)s1[i];
		i++;
	}
	ans[i] = '\0';
	return ((char *)ans);
}
