/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fzucconi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:20:06 by fzucconi          #+#    #+#             */
/*   Updated: 2023/10/12 17:20:06 by fzucconi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char sep)
{
	if (c == sep)
		return (1);
	return (0);
}

static int	get_word_count(char const *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && is_sep(*str, c))
			str++;
		if (*str && !is_sep(*str, c))
		{
			count++;
			while (*str && !is_sep(*str, c))
				str++;
		}
	}
	return (count);
}

static char	*get_word(char const *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && !is_sep(str[i], c))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	i = 0;
	while (str[i] && !is_sep(str[i], c))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	check_allocation(char **words, int i)
{
	int	j;

	j = 0;
	if (!words[i])
	{
		while (words[j])
			free(words[j++]);
		free(words);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**words;

	if (!str)
		return (0);
	i = 0;
	words = (char **)malloc(sizeof(char *) * (get_word_count(str, c) + 1));
	if (!words)
		return (0);
	while (*str)
	{
		while (*str && is_sep(*str, c))
			str++;
		if (*str && !is_sep(*str, c))
		{
			words[i] = get_word(str, c);
			if (!check_allocation(words, i))
				return (0);
			i++;
			while (*str && !is_sep(*str, c))
				str++;
		}
	}
	words[i] = 0;
	return (words);
}
