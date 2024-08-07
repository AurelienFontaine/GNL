/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontain <afontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 17:02:46 by afontain          #+#    #+#             */
/*   Updated: 2022/12/13 15:21:31 by afontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char *buffer)
{
	char	*str;
	int		reade;

	reade = 1;
	if (buffer[0] == '\0')
	{
		reade = read(fd, buffer, BUFFER_SIZE);
		buffer[reade] = '\0';
	}
	str = ft_calloc(BUFFER_SIZE + 1, 1);
	if (!str)
		return (NULL);
	while (!ft_strchr(buffer, '\n') && reade != 0)
	{
		str = ft_strjoin(str, buffer);
		reade = read(fd, buffer, BUFFER_SIZE);
		if (reade == -1)
			return (free(str), NULL);
		buffer[reade] = '\0';
	}
	str = ft_strjoin(str, buffer);
	return (str);
}

char	*line_to_buffer(char *str)
{
	size_t		i;
	char		*line;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
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
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	free(str);
	return (line);
}

void	read_next_line(char *line, char *buffer)
{
	size_t		i;
	size_t		j;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i])
		buffer[j++] = line[i++];
	while (j < BUFFER_SIZE + 1)
		buffer[j++] = '\0';
}

char	*get_next_line(int fd)
{
	static char		buffer[1024][BUFFER_SIZE + 1] = {0};
	char			*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	line = read_line(fd, buffer[fd]);
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	read_next_line(line, buffer[fd]);
	line = line_to_buffer(line);
	return (line);
}
