/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabde-s <isabde-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:28:15 by isabde-s          #+#    #+#             */
/*   Updated: 2025/12/05 13:28:20 by isabde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*stash[OPEN_MAX];
	char		*line;
	ssize_t		bytesRead;

	bytesRead = 0;
	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	while (!check_newline(stash[fd]))
	{
		bytesRead = read(fd, buffer, BUFFER_SIZE);
		if (bytesRead == -1)
			return (free(stash[fd]), stash[fd] = NULL, NULL);
		if (bytesRead <= 0)
			break ;
		buffer[bytesRead] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
	}
	if (!stash[fd] || stash[fd][0] == '\0')
		return (free(stash[fd]), stash[fd] = NULL, NULL);
	line = extract_line(stash[fd]);
	stash[fd] = clean_stash(stash[fd]);
	return (line);
}
// read = ssize_t read(int fd, void *buf, size_t count);