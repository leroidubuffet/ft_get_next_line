/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybolivar <ybolivar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:19:34 by ybolivar          #+#    #+#             */
/*   Updated: 2022/07/05 14:39:06 by ybolivar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_join_and_free(char *buffer, char *sub_bufer)
{
	char	*tmp;

	tmp = gnl_strjoin(buffer, sub_bufer);
	free(buffer);
	return (tmp);
}

static char	*ft_clean_buffer(char *buffer)
{
	int		n;
	int		m;
	char	*sub_buffer;

	n = 0;
	m = 0;
	if (!buffer)
		return (NULL);
	while (buffer[n] != '\n' && buffer[n])
		n++;
	if (!buffer[n])
	{
		free(buffer);
		return (NULL);
	}
	sub_buffer = gnl_calloc(gnl_strlen(buffer) - n + 1, sizeof(char));
	n++;
	while (buffer[n])
		sub_buffer[m++] = buffer[n++];
	free(buffer);
	return (sub_buffer);
}

static char	*ft_get_line(char *buffer)
{
	char	*line;
	int		n;

	n = 0;
	if (!buffer[n])
		return (NULL);
	while (buffer[n] != '\n' && buffer[n])
		n++;
	line = gnl_calloc(n + 2, sizeof(char));
	n = 0;
	while (buffer[n] != '\n' && buffer[n])
	{
		line[n] = buffer[n];
		n++;
	}
	if (buffer[n] == '\n' && buffer[n])
		line[n] = '\n';
	return (line);
}

static char	*ft_read_file(int fd, char *buffer)
{
	int		read_bytes;
	char	*sub_buffer;

	read_bytes = 1;
	if (!buffer)
		buffer = gnl_calloc(1, 1);
	sub_buffer = gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, sub_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			free(sub_buffer);
			return (NULL);
		}
		sub_buffer[read_bytes] = '\0';
		buffer = ft_join_and_free(buffer, sub_buffer);
		if (gnl_strchr(sub_buffer, '\n'))
			break ;
	}
	free(sub_buffer);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = ft_clean_buffer(buffer[fd]);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int		n;

	n = 0;
	fd = open("../alice29.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error opening source file.\n");
		return (1);
	}
	while (n < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		n++;
	}
	if (close(fd) != 0)
		printf("Error closing source file.\n");
	return (0);
}*/