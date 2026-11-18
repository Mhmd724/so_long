/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mharajli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:51:07 by mharajli          #+#    #+#             */
/*   Updated: 2024/07/18 09:53:56 by mharajli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE];
	static int		buf_pos = 0;
	static int		buf_size = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	return (read_line(buffer, &buf_pos, &buf_size, fd));
}
