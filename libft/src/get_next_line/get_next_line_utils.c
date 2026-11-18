/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:51:44 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 09:57:45 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*append_char_to_line(char *line, char c, int line_len)
{
	char	*new_line;
	int		i;

	new_line = (char *)malloc(line_len + 2);
	if (!new_line)
		return (NULL);
	i = 0;
	while (i < line_len)
	{
		new_line[i] = line[i];
		i++;
	}
	new_line[line_len] = c;
	new_line[line_len + 1] = '\0';
	free(line);
	return (new_line);
}

ssize_t	buffer_read(char *buf, int *buf_pos, int *buf_size, int fd)
{
	*buf_size = read(fd, buf, BUFFER_SIZE);
	*buf_pos = 0;
	return (*buf_size);
}

char	*read_line(char *buf, int *buf_pos, int *buf_size, int fd)
{
	char	*line;
	int		line_len;
	char	c;

	line_len = 0;
	line = NULL;
	while (1)
	{
		if (*buf_pos >= *buf_size)
		{
			if (buffer_read(buf, buf_pos, buf_size, fd) <= 0)
			{
				if (line_len > 0)
					return (line);
				free(line);
				return (NULL);
			}
		}
		c = buf[(*buf_pos)++];
		line = append_char_to_line(line, c, line_len++);
		if (!line || c == '\n')
			break ;
	}
	return (line);
}
