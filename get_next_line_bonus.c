/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manavarr <manavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:54:37 by manavarr          #+#    #+#             */
/*   Updated: 2022/11/28 17:54:37 by manavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	if (size && (size_t)-1 / size < count)
		return (NULL);
	res = (void *)malloc(size * count);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		((char *)res)[i] = '\0';
		i++;
	}
	return (res);
}

char	*ft_read_line(int fd, char *buffer)
{
	char	*buff;
	int		size;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	size = 1;
	while (!ft_strchr(buffer, '\n') && size != 0)
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (size == -1)
		{
			free(buff);
			free(buffer);
			return (NULL);
		}
		buff[size] = '\0';
		buffer = ft_strjoin(buffer, buff);
	}
	free(buff);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*ln;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	ln = (char *)ft_calloc(i + 2, sizeof(char));
	if (!ln)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		ln[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		ln[i] = buffer[i];
		i++;
	}
	return (ln);
}

char	*ft_remove_line(char *buffer)
{
	char	*next;
	int		i;
	int		o;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = (char *)ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	if (!next)
		return (0);
	i++;
	o = 0;
	while (buffer[i])
		next[o++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*get_next_line(int fd)
{
	static char	*buffer[256];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (0);
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_remove_line(buffer[fd]);
	return (line);
}
