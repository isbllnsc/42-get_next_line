/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isabde-s <isabde-s@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:28:15 by isabde-s          #+#    #+#             */
/*   Updated: 2025/12/16 13:28:20 by isabde-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_newline(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	s3 = malloc(i + j + 1);
	if (!s3)
		return (free(s1), NULL);
	j = 0;
	while (s1[j])
	{
		s3[j] = s1[j];
	}
	i = 0;
	while (s2[i])
		s3[j++] = s2[i++];
	s3[j] = '\0';
	return (free(s1), s3);
}

char	*extract_line(char *stash)
{
	char		*line;
	int			i;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line [i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*clean_stash(char *stash)
{
	int			i;
	int			len;
	char		*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	len = 0;
	while (stash[i + len])
		len++;
	new_stash = malloc(len + 1);
	if (!new_stash)
		return (free(stash), NULL);
	len = 0;
	while (stash[i])
		new_stash[len++] = stash[i++];
	new_stash[len] = '\0';
	free(stash);
	return (new_stash);
}