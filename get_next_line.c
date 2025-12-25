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

// assinatura de read = ssize_t read(int fd, void *buf, size_t count);

char	*get_next_line(int fd)
{
    static char	*stash[OPEN_MAX];
	char	*line;
    char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (!check_newline(stash[fd]))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		if (bytes_read <= 0)
			break;
		buffer[bytes_read] = '\0';
		stash[fd] = ft_strjoin(stash[fd], buffer);
}

		if (!stash[fd] || stash[fd][0] == '\0')
		{
			free(stash[fd]);
			stash[fd] = NULL;
			return (NULL);
		}