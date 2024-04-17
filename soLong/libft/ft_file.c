/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaydogd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:52:51 by emaydogd          #+#    #+#             */
/*   Updated: 2023/05/11 13:11:59 by emaydogd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	file_len(const char *filename)
{
	int		fd;
	int		len;
	int		size_read;
	char	buffer[BUFFER_SIZE];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	len = 0;
	while (1)
	{
		size_read = read(fd, buffer, BUFFER_SIZE);
		if (!size_read)
			break ;
		len += size_read;
	}
	close(fd);
	return (len);
}

char	*ft_file_read(char *filename)
{
	int		fd;
	int		idx;
	char	*ret;
	char	buffer[1];

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	ret = malloc((file_len(filename) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	idx = 0;
	while (read(fd, buffer, 1))
		ret[idx++] = *buffer;
	ret[idx] = '\0';
	close(fd);
	return (ret);
}