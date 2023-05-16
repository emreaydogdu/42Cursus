/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:09:10 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/16 23:06:12 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_before(const char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == '\0')
	{
		return (NULL);
	}
	ptr = malloc(sizeof(char) * i + 2);
	if (!ptr)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		ptr[i++] = '\n';
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_after(char *str)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	j = 0;
	i = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[j] != '\n' && str[j])
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (NULL);
	}
	ptr = malloc(sizeof(char) * (i - j));
	if (!ptr)
		return (NULL);
	i = 0;
	j++;
	while (str[j])
		ptr[i++] = str[j++];
	ptr[i] = '\0';
	free(str);
	return (ptr);
}
/*
char	**ft_front(char *str)
{
	char	*s[2];
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	len = _ft_strlen(str);
	while (str[i] && str[i] != '\n')
		i++;
	i++;
	s[0] = malloc(sizeof(char) * i);
	s[1] = malloc(sizeof(char) * len - i);
	if (!s[0] || !s[1])
		return (NULL);
	j = len - i + 1;
	s[1][j] = '\0';
	while (j)
		s[1][--j] = str[len--];
	s[0][i] = '\0';
	while (i--)
		s[0][i] = str[i];
	free(str);
	return (s);
}
*/

int	ft_nlchr(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (*str++ == '\n')
			return (1);
	return (0);
}

char	*ft_read(int fd, char *buf, char *tmp, char *str)
{
	ssize_t	i;

	i = 1;
	while (i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		tmp = str;
		if (!tmp)
		{
			tmp = malloc(sizeof(char) * 1);
			tmp[0] = '\0';
		}
		str = ft_strjoin(tmp, buf);
		free(tmp);
		if (ft_nlchr(str))
			break ;
	}
	free(buf);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*buf;
	char		*line;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	str = ft_read(fd, buf, tmp, str);
	if (!str)
		return (NULL);
	line = ft_before(str);
	str = ft_after(str);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	FILE	*f;
	char	*line = NULL;
	size_t	len = 0;

	fd = open("../getNextLine/file", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s %s", get_next_line(fd), NULL);
	close(fd);
	//printf("\nSPLIT  ->|%s|", ft_front("1. Line -> Hello\n2. ")[0]);
	printf("\n\nBUFFER -> %d\n\n", BUFFER_SIZE);
	f = fopen("../getNextLine/file", "r");
	getline(&line, &len, f);
	printf("%s", line);
	getline(&line, &len, f);
	printf("%s", line);
	getline(&line, &len, f);
	printf("%s", line);
	getline(&line, &len, f);
	printf("%s", line);
	getline(&line, &len, f);
	printf("%s", line);
	getline(&line, &len, f);
	printf("%s", line);
	getline(&line, &len, f);
	printf("%s", line);
	getline(&line, &len, f);
	printf("%s", line);
	return (0);
}
*/