/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-08 20:13:08 by slaaouin          #+#    #+#             */
/*   Updated: 2025-11-08 20:13:08 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*ft_extract_line(char *str, int *index)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = '\n';
		i++;
		line[i] = '\0';
	}
	else
		line[i] = '\0';
	*index = i;
	return (line);
}

char	*ft_read_file(int fd, char *buff)
{
	char	*buffer;
	ssize_t	bytes;
	char	*tp;

	bytes = 1;
	while (bytes > 0)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return (buff);
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes <= 0)
		{
			free(buffer);
			break ;
		}
		buffer[bytes] = '\0';
		tp = ft_strjoin(buff, buffer);
		free(buffer);
		free(buff);
		buff = tp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (buff);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	int			index;
	char		*tp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	index = 0;
	if (!buff)
		buff = ft_strdup("");
	buff = ft_read_file(fd, buff);
	if (!buff || !*buff)
	{
		free(buff);
		buff = NULL;
		return (NULL);
	}
	line = ft_extract_line(buff, &index);
	if (!line || !*line)
	{
		free(buff);
		return (NULL);
	}
	tp = ft_strdup(&buff[index]);
	free(buff);
	buff = tp;
	return (line);
}
